
#ifndef NEURON_H
#define NEURON_H

#include "matrix.h"
#include "activation.h"

typedef struct Layer {
	Matrix *weights;
	Matrix *bias;
	ActivationFunction activation;
} Layer;

Matrix *neuron(Matrix *inputs, Layer layer);

#endif // NEURON_H
