#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

int compare(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int N, *arr, crit, i, sum = 0;
	
	scanf("%d", &N);
	crit = (int)round(N * 0.15);
	
	if (N <= crit * 2) {
		printf("0");
		return 0;
	}
	
	arr = (int*)malloc(N * sizeof(int));
	
	for (i = 0; i < N; i++) scanf("%d", &(arr[i]));
	qsort(arr, N, sizeof(arr[0]), compare);
	
	for (i = crit; i < N - crit; i++) sum += arr[i];
	printf("%d", (int)round(sum / (double)(N - crit * 2)));
	
	return 0;
}
