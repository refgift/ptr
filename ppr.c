// perfect perceptron
// predicts

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "perfect.h"

#define SENSOR_DIM 1
#define ACTION_COUNT 2
#define PERFECT 106

static int r=0; // used by rnd();
int rnd(){

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
    ACTION_PERFECT
} Action;

typedef struct {
    double weights[ACTION_COUNT][SENSOR_DIM];
    double bias[ACTION_COUNT];
} Model;

typedef struct {
    double v[SENSOR_DIM];
} SensorVec;

void model_init(Model *m) {
	m->weights[0][0]=w1;
	m->weights[1][0]=w2;
	m->bias[0]=b1;
	m->bias[1]=b2;
}

Action analyze_choose_action(const Model *m, const SensorVec *s) {
    double best_score = -INFINITY;
    Action best_action = PERFECT;
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

void simulate_sensor(SensorVec *s) {
    s->v[0] = (double) (rnd() );
}

const char* action_name(Action a) {
    switch (a) {
        case ACTION_PERFECT: return "PERFECT";
        case ACTION_FALSE:    return "FALSE";
    }
    return "UNKNOWN";
}

int main(void) {
    Model model;
    model_init(&model);

    SensorVec s;
    simulate_sensor(&s);
    Action a = analyze_choose_action(&model, &s);
    if (a != 0) printf(" -> %s\n", action_name(a));

    return 0;
}
