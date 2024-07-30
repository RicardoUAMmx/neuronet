#include "activation.h"
#include <stdlib.h>
#include <math.h>


Matrix *hardLimit(Matrix *m) {
	Matrix *m_temp = createMatrix(m->rows, m->cols);
	for (int i = 0; i < m->rows; i++) {
		for (int j = 0; j < m->cols; j++) {
			m_temp->value[i][j] = m->value[i][j] >= 0.0 ? 1.0 : 0.0;
		}
	}
	return m_temp;
}

Matrix *sigmoid(Matrix *m) {
	Matrix *m_temp = createMatrix(m->rows, m->cols);
	for (int i = 0; i < m->rows; i++) {
		for (int j = 0; j < m->cols; j++) {
			m_temp->value[i][j] = 1 / (1 + exp(-m->value[i][j]));
		}
	}
	return m_temp;
}
