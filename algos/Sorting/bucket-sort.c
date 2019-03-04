#include<stdio.h>
#include<stdlib.h>

typedef struct node_ NODE;

struct node_ {
	float val;
	NODE* next;
};

void bucketSort (float A[], int n, int noBuckets) {
	NODE* buckets[noBuckets];

	for (int i = 0; i < n; i++) {
		NODE* sentinal = (NODE *) malloc(sizeof(NODE));
		sentinal->next = NULL;
		buckets[i] = sentinal;
	}

	for (int i = 0; i < n; i++) {
		int bucketIndex = A[i] * noBuckets;

		NODE *n = (NODE *) malloc(sizeof(NODE));
		n->val = A[i];
		n->next = NULL;

		NODE* tmp = buckets[bucketIndex];
		while (tmp->next) {
			if (tmp->next->val > A[i]) {
				n->next = tmp->next;
				break;
			}
			else tmp = tmp->next;
		}
		tmp->next = n;
	}

	for (int i = 0; i < noBuckets; i++) {
		if (buckets[i]->next) {
			NODE* t = buckets[i]->next;
			while (t) {
				printf("%f ", t->val);
				t = t->next;
			}
		}
	}
}

int main () {
	float A[5] = {0.3, 0.23, 0.54, 0.11, 0.756};
	bucketSort(A, 5, 5);
}
