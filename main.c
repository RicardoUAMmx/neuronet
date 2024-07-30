#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "activation.h"
#include "neuron.h"

int main() {
	Matrix *input = createMatrix(3, 1);
	fillMatrix(input, 2);

	Layer layer;
	layer.weights = createMatrix(2, 3);
	layer.weights->value[0][0] = 0.5; layer.weights->value[0][1] = 0.5; layer.weights->value[0][2] = 0.5;
	layer.weights->value[1][0] = 0.5; layer.weights->value[1][1] = 0.5; layer.weights->value[1][2] = 0.5;

	layer.bias = createMatrix(2, 1);
	fillMatrix(layer.bias, 0.5);

	layer.activation = sigmoid;
	Matrix *output = neuron(input, layer);
	if (output == NULL) {
		fprintf(stderr, "Error: neuron() returned NULL\n");
		freeMatrix(&input);
		freeMatrix(&layer.weights);
		freeMatrix(&layer.bias);
		return EXIT_FAILURE;
	}

	printf("Output:\n");
	printMatrix(output);

	freeMatrix(&input);
	freeMatrix(&layer.weights);
	freeMatrix(&layer.bias);
	freeMatrix(&output);

	return EXIT_SUCCESS;
}
