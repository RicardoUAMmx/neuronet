#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>


Matrix *createMatrix(int rows, int cols) {
	Matrix *m = (Matrix *)malloc(sizeof(Matrix));
	if (m == NULL) {
		fprintf(stderr, "Memory allocation failed for matrix struct\n");
		exit(EXIT_FAILURE);
	}
	m->rows = rows;
	m->cols = cols;
	m->value = (float **)malloc(rows * sizeof(int *));
	if (m->value == NULL) {
		fprintf(stderr, "Memory allocation failed for matrix value\n");
		free(m);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < rows; i++) {
		m->value[i] = (float *)malloc(cols * sizeof(int));
		if (m->value[i] == NULL) {
			fprintf(stderr, "Memory allocation failed for matrix row\n");
			for (int j = 0; j < i; j++) {
				free(m->value[j]);
			}
			free(m->value);
			free(m);
			exit(EXIT_FAILURE);
		}
	}
	return m;
}

void freeMatrix(Matrix **m) {
	if (m && *m) {
		for (int i = 0; i < (*m)->rows; i++) {
			free((*m)->value[i]);
		}
		free((*m)->value);
		free(*m);
		*m = NULL;
	} else {
		fprintf(stderr, "Matrix is NULL\n");
		exit(EXIT_FAILURE);
	}
}

void printMatrix(Matrix *m) {
	for (int i = 0; i < m->rows; i++) {
		for (int j = 0; j < m->cols; j++) {
			printf("%.6f ", m->value[i][j]);
		}
		printf("\n");
	}
}

Matrix *multiplyMatrix(Matrix *m_a, Matrix *m_b) {
	if (m_a->cols != m_b->rows) {
		fprintf(stderr, "Matrix dimensions are not compatible for multiplication\n");
		return NULL;
	}
	Matrix *m_c = createMatrix(m_a->rows, m_b->cols);
	for (int i = 0; i < m_a->rows; i++) {
		for (int j = 0; j < m_b->cols; j++) {
			m_c->value[i][j] = 0;
			for (int k = 0; k < m_a->cols; k++) {
				m_c->value[i][j] += m_a->value[i][k] * m_b->value[k][j];
			}
		}
	}
	return m_c;
}

Matrix *addMatrix(Matrix *m_a, Matrix *m_b) {
	if (m_a->rows != m_b->rows || m_a->cols != m_b->cols) {
		fprintf(stderr, "Matrix dimensions are not compatible for addition\n");
		return NULL;
	}
	Matrix *m_c = createMatrix(m_a->rows, m_a->cols);
	for (int i = 0; i < m_a->rows; i++) {
		for (int j = 0; j < m_a->cols; j++) {
			m_c->value[i][j] = m_a->value[i][j] + m_b->value[i][j];
		}
	}
	return m_c;
}

void fillMatrix(Matrix *m, float value) {
	for (int i = 0; i < m->rows; i++) {
		for (int j = 0; j < m->cols; j++) {
			m->value[i][j] = value;
		}
	}
}

