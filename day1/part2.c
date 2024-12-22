#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 1000

int unique_elements(int *dst, int *src, int size);

int main() {
	int firstNum = 0, secondNum = 0;
	FILE* fptr = fopen("input.txt", "r");

	int *rawLeftArr = (int*)calloc(INPUT_SIZE, sizeof(int));
	int *rawRightArr = (int*)calloc(INPUT_SIZE, sizeof(int));

	int i = 0, j = 0;

	while (fptr != NULL) {
		fscanf(fptr, "%d\t%d", &firstNum, &secondNum);
		rawLeftArr[i++] = firstNum;
		rawRightArr[j++] = secondNum;
		if (feof(fptr)) break;
	}

	int result = 0;

	int *uniqueLeftArr = (int*)calloc(INPUT_SIZE, sizeof(int));
	int uniqueCount = unique_elements(uniqueLeftArr, rawLeftArr, INPUT_SIZE);

	for (int i = 0; i < uniqueCount; ++i) {
		int repeated = 0, occurences = 0;
		for (int j = 0; j < INPUT_SIZE; ++j) {
			repeated += rawLeftArr[j] == uniqueLeftArr[i] ? 1 : 0;
			occurences += rawRightArr[j] == uniqueLeftArr[i] ? 1 : 0;
		}
		result += uniqueLeftArr[i] * repeated * occurences;
	}

	printf("The final score is: %d\n", result);
}

int unique_elements(int *dst, int *src, int size) {
	memset(dst, size, 0);
	dst[0] = src[0];
	int unique_count = 1;

	for (int i = 0; i < size; ++i) {
		int j = 0;

		for (j = 0; j < unique_count; ++j) {
			if (src[i] == dst[j]) break;
		}

		if (j == unique_count) {
			unique_count++;
			dst[unique_count-1] = src[i];
		}
	}

	return unique_count;
}
