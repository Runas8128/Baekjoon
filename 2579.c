#include <stdio.h>
#include <malloc.h>

#define MAX(x, y) (x) > (y) ? (x) : (y)

int proceed(int* arr, int size, int index, int firstCount) {
	int max = -1, chk = -1;
	
	if (size == index) return 0;
	
	if (index + 1 < size && firstCount < 3) max = proceed(arr, size, index+1, firstCount+1);
	if (index + 2 < size && (chk = proceed(arr, size, index+2, 0)) > max) max = chk;
	if (index + 3 < size && (chk = proceed(arr, size, index+3, 0)) > max) max = chk;
}

int main() {
	int N, *arr;
	
	scanf("%d", &N);
	arr = (int*)malloc(N * sizeof(int));
	
	for (i = 0; i < N; i++) scanf("%d", &(arr[i]));
	
	printf("%d", proceed(arr, N, 0, 0));
	
	return 0;
}
