#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define ARRAY_SIZE 10
void merge(int *arr, int start, int mid, int end)
{
	int *leftArr, *rightArr;
	int leftSize, rightSize;
	int left = 0, right = 0, index = start;
	
	leftSize = mid - start + 1;
	rightSize = end - mid;

	leftArr = (int *)malloc(sizeof(int) * leftSize);
	memcpy((void *)leftArr, &arr[start], leftSize * sizeof(int));

	rightArr = (int *)malloc(sizeof(int) * rightSize);
	memcpy((void *)rightArr, &arr[mid + 1], rightSize * sizeof(int));

	while((left < leftSize) && (right < rightSize))
	{
		arr[index++] = leftArr[left] < rightArr[right] ? leftArr[left++] : rightArr[right++];		
	}

	while(left < leftSize)
	{
		arr[index++] = leftArr[left++];
	}

	while(right < rightSize)
	{
		arr[index++] = rightArr[right++];
	}
}

void merge_sort(int *arr, int start, int end)
{
	int mid;

	if(start < end)
	{
		mid = (start + end) / 2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

int main()
{
	int array[ARRAY_SIZE] = {2, 3, 12, 34, 55, 43, 21, 17, 89, 55};
	int count;

	printf("origin data: \n");
	for(count = 0; count < ARRAY_SIZE; count++)
	{
		printf("array[%d] = %d\n", count, array[count]);
	}
	merge_sort(array, 0, ARRAY_SIZE - 1);
	printf("new data: \n");
	for(count = 0; count < ARRAY_SIZE; count++)
	{
		printf("array[%d] = %d\n", count, array[count]);
	}
	return 0;
}




