#include "neuron.h"
#include <stdlib.h>
#include <stdio.h>

void activate(Matrix **m, ActivationFunction f) {
	Matrix *m_temp = f(*m);
	freeMatrix(m);
	*m = m_temp;
}

Matrix *neuron(Matrix *inputs, Matrix *weights, Matrix *bias, ActivationFunction f) {
	Matrix *m_temp = multiplyMatrix(weights, inputs);
	if (m_temp == NULL) {
		return NULL;
	}

	Matrix *m_temp2 = addMatrix(m_temp, bias);
	freeMatrix(&m_temp);
	if (m_temp2 == NULL) {
		return NULL;
	}

	activate(&m_temp2, f);
	return m_temp2;
}
