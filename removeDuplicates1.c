/*************************************************************************************/
/* Given an integer array nums sorted in non-decreasing order, remove the duplicates */
/*     in-place such that each unique element appears only once.		     */
/*     The relative order of the elements should be kept the same.		     */
/* 										     */
/* Since it is impossible to change the length of the array in some languages,	     */
/*     you must instead have the result be placed in the first part of the array     */
/*     nums. More formally, if there are k elements after removing the duplicates,   */
/*     then the first k elements of nums should hold the final result. It does not   */
/*     matter what you leave beyond the first k elements.			     */
/* 										     */
/* Return k placing the final result in the first k slots of nums.		     */
/* 										     */
/* Do not allocate extra space for another array. You must do this by modifying	     */
/*    the input array in-place with O(1) extra memory.				     */
/*************************************************************************************/

//TODO: make an O(n) solution

#include <stdio.h>

#define ARRSZ(a) (sizeof(a)/sizeof(a[0]))

int removeDuplicates(int *nums, int size);

int main()
    {
    int arr[] = {1,2,3,3,4,5,6,6,6};
    int res = removeDuplicates(arr, ARRSZ(arr));
    printf("res: %d\n", res);
    for (int i = 0; i < res; ++i)
	printf("arr[%d]: %d\n", i, arr[i]);
	
    return (0);
    }

int sameElems(int *arr, int size)
    {
    int ret = 1;
    for (size_t i = 0; i < size-1; ++i)
	{
	if (arr[i] != arr[i+1])
	    {
	    ret = 0;
	    break;
	    }
	}
    return (ret);
    }

int removeDuplicates(int *nums, int size)
    {
    if(sameElems(nums, size))
	return (1);

    for (size_t i = 0; i < size-1; ++i)
	{
	while (nums[i] == nums[i+1])
	    {
	    for (size_t j = i; j < size-1; ++j)
		nums[j] = nums[j+1];
	    if (i == size-1 || size == 2)
		break;
	    --size;
	    }
	}
    return (size);
    }
