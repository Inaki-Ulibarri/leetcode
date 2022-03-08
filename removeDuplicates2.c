/*************************************************************************************************/
/* Given an integer array nums sorted in non-decreasing order, remove the duplicates		 */
/* 	in-place such that each unique element appears only once. The relative order		 */
/* 	of the elements should be kept the same.						 */
/* 												 */
/* Since it is impossible to change the length of the array in some languages, you must		 */
/* 	instead have the result be placed in the first part of the array nums.			 */
/* 	More formally, if there are k elements after removing the duplicates, then the		 */
/* 	first k elements of nums should hold the final result. It does not matter what		 */
/* 	you leave beyond the first k elements.							 */
/* 												 */
/* Return k after placing the final result in the first k slots of nums.			 */
/* 												 */
/* Do not allocate extra space for another array. You must do this by modifying the		 */
/*        input array in-place with O(1) extra memory.						 */
/*************************************************************************************************/

#include <stdio.h>

#define ARRSZ(a) (sizeof(a)/sizeof(a[0]))
int removeDuplicates(int *arr, int size);

/**
 * TODO: fix the break sequence in removeDuplicates()
 */
int main()
{
	int arr[] = {1,2,2};
	int res = removeDuplicates(arr, ARRSZ(arr));
	for (size_t i = 0; i < res; ++i)
		printf("arr[%zu]: %d\n", i, arr[i]);
	putchar('\n');

	return (0);
}

int nextHigh(int *arr, int size, int ind)
{
	for(int i = ind; i < size-1; ++i) {
		if (arr[i] < arr[i+1])
			return (i+1);
	}
	return (-1);
}

int arraySame(int *arr, int size)
{
	int ret = 1;
	for (int i = 0; i < size-1; ++i) {
		if (arr[i] != arr[i+1]) {
			ret = 0;
			break;
		}
	}
	return (ret);
}

int removeDuplicates(int *arr, int size)
{
	int p = 1;
	int res = 1;
	for (int i = 1; i < size-1; ++i) {
	        p = nextHigh(arr, size, p);
		if (p == -1) {
			return (i);
		}
		arr[i] = arr[p];
		++res;
	}
	return (res);
}

// 1 2 3 4 5 5 5 6 7 8
