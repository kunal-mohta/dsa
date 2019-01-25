// FOR DSA COURSE (CS F211)

#include<stdio.h>
#include "../../utilities.h"

void merge(int[], int, int, int);

void mergeSort (int arr[], int startIndex, int endIndex) {
	if (startIndex < endIndex) {
		int midIndex = (startIndex + endIndex) / 2;
		mergeSort(arr, startIndex, midIndex);
		mergeSort(arr, midIndex + 1, endIndex);
		merge(arr, startIndex, midIndex, endIndex);
	}
}

void merge (int arr[], int startIndex, int midIndex, int endIndex) {
	int lArrSize = midIndex - startIndex + 1;
	int rArrSize = endIndex - midIndex;

	int lArray[lArrSize];
	int rArray[rArrSize];
	int finalArray[lArrSize + rArrSize];

	int i;
	for (i = startIndex; i <= midIndex; i++) lArray[i - startIndex] = arr[i];
	for (i = midIndex + 1; i <= endIndex; i++) rArray[i - midIndex - 1] = arr[i];

	int lArrPointer = startIndex;
	int rArrPointer = midIndex + 1;

	int finalArrayIndex = 0;

	int lArrDone = 0;
	int rArrDone = 0;

	while (1) {
		if (lArrPointer == startIndex + lArrSize) {
			lArrDone = 1;
			break;
		}
		else if (rArrPointer == midIndex + rArrSize + 1) {
			rArrDone = 1;
			break;
		}

		if (arr[lArrPointer] <= arr[rArrPointer]) {
			finalArray[finalArrayIndex] = arr[lArrPointer];
			lArrPointer++;
		}
		else {
			finalArray[finalArrayIndex] = arr[rArrPointer];
			rArrPointer++;
		}
		finalArrayIndex++;
	}

	if (lArrDone) {
		while (rArrPointer < midIndex + rArrSize + 1) {
			finalArray[finalArrayIndex] = arr[rArrPointer];
			rArrPointer++;
			finalArrayIndex++;
		}
	}
	else if (rArrDone) {
		while (lArrPointer < startIndex + lArrSize) {
			finalArray[finalArrayIndex] = arr[lArrPointer];
			lArrPointer++;
			finalArrayIndex++;
		}
	}

	for (int j = startIndex; j <= endIndex; j++) arr[j] = finalArray[j - startIndex];
}

int main () {
	int arr[] = {1,4,5,3,2};
	mergeSort(arr, 0, 4);
	printIntArray(arr, 5, "arr");
}

