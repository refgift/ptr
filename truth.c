// truth perceptron
// trains and predicts
// Generates C Language format weights and bias.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SENSOR_DIM 1
#define ACTION_COUNT 2 
#define TRAINING_SAMPLES 496
#define LEARNING_RATE 0.05
#define EPOCHS 15
#define TRUTH 66

int rnd(){
	int r;
	char success;
	asm volatile("rdrand %0; setc %1" : "=r"(r), "=qm"(success));
	if (!success) {
		// Fallback if rdrand fails
		r = rand();
	}
	return r;
}

typedef enum {
    ACTION_FALSE,
    ACTION_TRUTH
} Action;

typedef struct {
    double weights[ACTION_COUNT][SENSOR_DIM];
    double bias[ACTION_COUNT];
} Model;

typedef struct {
    double v[SENSOR_DIM];
} SensorVec;

double random_double(double low, double high)
{
    return low + (high - low) * rnd();
}

static double randd(double a, double b) {

	return random_double(a,b);
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
    Action best_action = TRUTH;
    for (int a = 0; a < ACTION_COUNT; ++a) {
        double score = m->bias[a];
        for (int i = 0; i < SENSOR_DIM; ++i)
            score += m->weights[a][i] * s->v[i];
        if (score > best_score) {
            best_score = score;
            best_action = (Action)a;
        }
    }
    return best_action;
}

// "Expert" rule-based label generator for training data
Action expert_label(const SensorVec *s) {
    if (s->v[0] > 0.8 ) return ACTION_TRUTH;
    return ACTION_FALSE;
}

int model_update(Model *m, const SensorVec *s, Action expert) {
   double error=0.0; 
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
//	fprintf(stderr,"Error: %e\n",error);
    }
	return 0;
}
void simulate_sensor(SensorVec *s) {
    s->v[0] = (double) (rnd() );
}

const char* action_name(Action a) {
    switch (a) {
        case ACTION_TRUTH: return "TRUTH";
        case ACTION_FALSE:    return "FALSE";
    }
    return "UNKNOWN";
}

int main(void) {
    Model model;
    model_init(&model);
    int quit=0;

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
   FILE * h=fopen("truth.h","w");
   fprintf(h,"// Truth Model 12/18/2025\n");
   fprintf(h,"float w1=%f;\nfloat w2=%f;\nfloat b1=%f;\nfloat b2=%f;\n",model.weights[0][0],model.weights[1][0],model.bias[0],model.bias[1]);
   fclose(h);
    // PREDICTION PHASE (fixed model, no updates)
//    printf("--- Prediction Phase ---\n");
//    for (int i = 0; i < 10; ++i) {
        SensorVec s;
	simulate_sensor(&s);
        Action a = analyze_choose_action(&model, &s);
	if  (a!=0) printf(" -> %s\n", action_name(a));
 //   }


    return 0;
}