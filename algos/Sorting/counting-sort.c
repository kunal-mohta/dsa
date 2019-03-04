#include<stdio.h>
#include "../../utilities.h"

void countingSort (int A[], int n, int k, int B[]) {
	int C[k];
	for (int i = 0; i < k+1; i++) C[i] = 0;

	// freq count
	for (int i = 0; i < n; i++) C[A[i]]++;

	// cumulative freq count
	for (int i = 1; i < k+1; i++) C[i] = C[i] + C[i-1];

//	for (int i = 0; i < k+1; i++) printf("%d", C[i]);

	for (int i = n-1; i >= 0; i--) {
	  	C[A[i]]--;
		B[C[A[i]]] = A[i];
	}
}

int main () {
	int A[8] = {3,2,4,5,4,2,10,3};
	int B[8];

	countingSort(A, 8, 10, B);

	printIntArray(B, 8, "");
}
