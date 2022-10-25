#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int (*arr)[30] = malloc(sizeof(int[20][30]));

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			arr[i][j] = i + j;
		}
	}

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			printf("%u ", arr[i][j]);
		}
		printf("\n");
	}

	free(arr);


	return 0;
}
