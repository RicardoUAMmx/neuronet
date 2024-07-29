
#ifndef NEURON_H
#define NEURON_H

#include "matrix.h"
#include "activation.h"

Matrix *neuron(Matrix *inputs, Matrix *weights, Matrix *bias, ActivationFunction activation);

#endif // NEURON_H
