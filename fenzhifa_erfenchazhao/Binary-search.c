#include <stdio.h>
#include <stdlib.h>
int query(int a[], int n, int value);
int main()
{
	int* ptr, n, i, value;

	printf("Input the number of array elements:");
	scanf_s("%d", &n);
	if ((ptr = (int*)calloc(n, sizeof(int))) == NULL){
		printf("Not able to callocate memory");
		exit(1);
	}
	printf("Input array element:");
	for (i = 0; i < n; i++) {
		scanf_s("%d", ptr + i);
	}
	printf("value:");
	scanf_s("%d", &value);
	printf("number(value):%d", query(ptr, n, value));
	free(ptr);

	return 0;
}
int query(int a[], int n, int value)
{
	int mid, left, right;

	left = 0, right = n - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (value == a[mid]) {
			break;
		}
		else if (value < a[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return mid;
}
