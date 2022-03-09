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

int main()
{
	int arr[] = {1,2,2};
	int res = removeDuplicates(arr, ARRSZ(arr));
	for (size_t i = 0; i < res; ++i)
		printf("arr[%zu]: %d\n", i, arr[i]);
	putchar('\n');

	return (0);
}

//solution from https://leetcode.com/problems/remove-duplicates-from-sorted-array/discuss/449156/C-solution, fucking kill me already
int removeDuplicates(int* nums, int numsSize)
{
	int dups = 0;
	for (int i = 1; i < numsSize; ++i) {
		if (nums[i-1] < nums[i]) 
			nums[i-dups] = nums[i];
		else
			++dups;
	}
	return (numsSize-dups);
}
