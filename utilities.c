#include <stdio.h>

void printIntArray (int arr[], int size, char prefix[]) {
	for (int i = 0; i < size; i++) printf("%s %d\n", prefix, arr[i]);
}
