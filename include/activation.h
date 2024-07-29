
#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "matrix.h"

typedef Matrix* (*ActivationFunction)(Matrix*);

Matrix *hardLimit(Matrix *m);
Matrix *sigmoid(Matrix *m);

#endif // ACTIVATION_H
