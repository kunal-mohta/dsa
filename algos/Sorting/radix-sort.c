#include<stdio.h>
#include "../../utilities.h"

int digitAt (int num, int position) {
	int key = num;
	int x = position;
	while (x) {
		key /= 10;
		x--;
	}
	key = key % 10;

	return key;
}

// works even for array of numbers with unequal number of digits
// because of the design of the function digitAt(int, int)
void radixSort (int A[], int n, int radix) {
	int B[n], C[10];
	for (int i = 0; i < radix; i++) {
		// customized counting sort
		for (int j = 0; j < 10; j++) C[j] = 0;
		for (int j = 0; j < n; j++) {
			int key = digitAt(A[j], i);
			C[key]++;
		}
		for (int j = 1; j < 10; j++) C[j] += C[j-1];
		for (int j = n-1; j >= 0; j--)	{
			int key = digitAt(A[j], i);
			C[key]--;
			B[C[key]] = A[j];
		}
	}
	for (int i = 0; i < n; i++) A[i] = B[i];
}

int main () {
	int A[5] = {1, 123, 3, 665, 45};

	radixSort(A, 5, 3);
	printIntArray(A, 5, "");
}
