#include <stdio.h>
#include <stdlib.h>

#define INPUT_SIZE 1000

void selection_sort(int *arr, int size);

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

	int prevMinLeft = 0, prevMinRight = 0;

	selection_sort(rawLeftArr, INPUT_SIZE);
	selection_sort(rawRightArr, INPUT_SIZE);

	int result = 0;

	for (int i = 0; i < INPUT_SIZE; ++i) result += abs(rawLeftArr[i] - rawRightArr[i]);

	printf("The final result is: %d\n", result);


	free(rawLeftArr);
	free(rawRightArr);
	return 0;
}

void selection_sort(int *arr, int size) {
	for (int i = 0; i < size; ++i) {
		int min = arr[i], minIdx = i;

		for (int j = i; j < size; ++j) {
			minIdx = arr[j] < min ? j : minIdx;
			min = arr[j] < min ? arr[j] : min;
		}

		int temp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = temp;
	}
}
