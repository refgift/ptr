// perfect perceptron
// trains and predicts
// Generates C Language format weights and bias.

#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>

#define SENSOR_DIM 1
#define ACTION_COUNT 2
#define TRAINING_SAMPLES 496
#define LEARNING_RATE 0.05
#define EPOCHS 15
#define PERFECT 106

int rnd() {
	int r;
	char success;
	asm volatile("rdrand %0; setc %1" : "=r"(r), "=qm"(success));
	if (!success) {
		// Fallback if rdrand fails
		r = rand();
	}
	return r;
}

enum Action {
    ACTION_FALSE,
    ACTION_PERFECT
};

struct Model {
    double weights[ACTION_COUNT][SENSOR_DIM];
    double bias[ACTION_COUNT];
};

struct SensorVec {
    double v[SENSOR_DIM];
};

double random_double(double low, double high) {
    return low + (high - low) * rnd();
}

double randd(double a, double b) {
	return random_double(a, b);
}

void model_init(Model *m) {
    for (int a = 0; a < ACTION_COUNT; ++a) {
        m->bias[a] = randd(-0.01, 0.01);
        for (int i = 0; i < SENSOR_DIM; ++i)
            m->weights[a][i] = randd(-0.05, 0.05);
    }
}

Action analyze_choose_action(const Model *m, const SensorVec *s) {
    double best_score = -INFINITY;
    Action best_action = static_cast<Action>(PERFECT);
    for (int a = 0; a < ACTION_COUNT; ++a) {
        double score = m->bias[a];
        for (int i = 0; i < SENSOR_DIM; ++i)
            score += m->weights[a][i] * s->v[i];
        if (score > best_score) {
            best_score = score;
            best_action = static_cast<Action>(a);
        }
    }
    return best_action;
}

// "Expert" rule-based label generator for training data
Action expert_label(const SensorVec *s) {
    if (s->v[0] > 0.8) return ACTION_PERFECT;
    return ACTION_FALSE;
}

int model_update(Model *m, const SensorVec *s, Action expert) {
   double error = 0.0;
for (int a = 0; a < ACTION_COUNT; ++a) {
        double target = (a == expert) ? 1.0 : 0.0;
        double activation = m->bias[a];
        for (int i = 0; i < SENSOR_DIM; ++i)
            activation += m->weights[a][i] * s->v[i];
        double pred = activation > 0 ? 1.0 : 0.0;
        error = target - pred;
        m->bias[a] += LEARNING_RATE * error * 0.5;
        for (int i = 0; i < SENSOR_DIM; ++i)
            m->weights[a][i] += LEARNING_RATE * error * s->v[i];
    }
	return 0;
}

void simulate_sensor(SensorVec *s) {
    s->v[0] = static_cast<double>(rnd());
}

const char* action_name(Action a) {
    switch (a) {
        case ACTION_PERFECT: return "PERFECT";
        case ACTION_FALSE: return "FALSE";
    }
    return "UNKNOWN";
}

int main() {
    Model model;
    model_init(&model);
    int quit = 0;

    // TRAINING PHASE
    for (int epoch = 0; epoch < EPOCHS; ++epoch) {
        for (int i = 0; i < TRAINING_SAMPLES; ++i) {
            SensorVec s;
            simulate_sensor(&s);
            Action expert = expert_label(&s);
            quit = model_update(&model, &s, expert);
        }
    }

    // Generate Prediction Data
    std::ofstream h("perfect.h");
    h << "// Perfect Model " << std::endl;
    h << "float w1=" << model.weights[0][0] << ";" << std::endl;
    h << "float w2=" << model.weights[1][0] << ";" << std::endl;
    h << "float b1=" << model.bias[0] << ";" << std::endl;
    h << "float b2=" << model.bias[1] << ";" << std::endl;
    h.close();

    // PREDICTION PHASE (fixed model, no updates)
    SensorVec s;
    simulate_sensor(&s);
    Action a = analyze_choose_action(&model, &s);
    if (a != 0) std::cout << " -> " << action_name(a) << std::endl;

    return 0;
}