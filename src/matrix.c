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
	m->data = (int **)malloc(rows * sizeof(int *));
	if (m->data == NULL) {
		fprintf(stderr, "Memory allocation failed for matrix data\n");
		free(m);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < rows; i++) {
		m->data[i] = (int *)malloc(cols * sizeof(int));
		if (m->data[i] == NULL) {
			fprintf(stderr, "Memory allocation failed for matrix row\n");
			for (int j = 0; j < i; j++) {
				free(m->data[j]);
			}
			free(m->data);
			free(m);
			exit(EXIT_FAILURE);
		}
	}
	return m;
}

void freeMatrix(Matrix **m) {
	if (m && *m) {
		for (int i = 0; i < (*m)->rows; i++) {
			free((*m)->data[i]);
		}
		free((*m)->data);
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
			printf("%d ", m->data[i][j]);
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
			m_c->data[i][j] = 0;
			for (int k = 0; k < m_a->cols; k++) {
				m_c->data[i][j] += m_a->data[i][k] * m_b->data[k][j];
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
			m_c->data[i][j] = m_a->data[i][j] + m_b->data[i][j];
		}
	}
	return m_c;
}

void fillMatrix(Matrix *m, int value) {
	for (int i = 0; i < m->rows; i++) {
		for (int j = 0; j < m->cols; j++) {
			m->data[i][j] = value;
		}
	}
}

