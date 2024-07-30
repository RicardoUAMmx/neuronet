
#ifndef MATRIX_H
#define MATRIX_H

typedef struct Matrix {
	int rows;
	int cols;
	float **value;
} Matrix;

Matrix *createMatrix(int rows, int cols);
void freeMatrix(Matrix **m);
void printMatrix(Matrix *m);
Matrix *multiplyMatrix(Matrix *m_a, Matrix *m_b);
Matrix *addMatrix(Matrix *m_a, Matrix *m_b);
void fillMatrix(Matrix *m, float value);

#endif // MATRIX_H
