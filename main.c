#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "activation.h"
#include "neuron.h"

int main() {
	Matrix *input = createMatrix(3, 1);
	fillMatrix(input, 2);

	Matrix *weights = createMatrix(2, 3);
	weights->data[0][0] = 1; weights->data[0][1] = -1; weights->data[0][2] = 0;
	weights->data[1][0] = 0; weights->data[1][1] = 1; weights->data[1][2] = 1;

	Matrix *bias = createMatrix(2, 1);
	fillMatrix(bias, 1);

	Matrix *output = neuron(input, weights, bias, hardLimit);
	if (output == NULL) {
		fprintf(stderr, "Error: neuron() returned NULL\n");
		freeMatrix(&input);
		freeMatrix(&weights);
		freeMatrix(&bias);
		return EXIT_FAILURE;
	}

	printf("Output:\n");
	printMatrix(output);

	freeMatrix(&input);
	freeMatrix(&weights);
	freeMatrix(&bias);
	freeMatrix(&output);

	return EXIT_SUCCESS;
}
