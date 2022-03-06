#include <stdio.h>
#include <stdlib.h>

#define ARRSZ(arr) sizeof(arr)/sizeof(arr[0])

int* twoSum(int* nums, int numsSize, int target, int* returnSize);
void copyIArr(int src[], int tar[], int size);

int main()
{
	int nums[] = {2,7,11,15,6,3,8,1};
	int targ = 9;
	int retSize = 0;
	int *ret = twoSum(nums, ARRSZ(nums), targ, &retSize);

	printf("Target: %d\n", targ);
	printf("Array given: \n");
	for (size_t i = 0; i < ARRSZ(nums); ++i)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
	printf("Indexes in the array that sum up '%d':\n", targ);
	for (int i = 0; i < retSize; ++i)
	{
		printf("%d ", ret[i]);
	}
	printf("\n");
	return (0);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int *buf    = calloc(2, sizeof(int));
	int *buf2   = 0x0;
	size_t bufl = 2;
	int retSz = 0;
	//at least one possible pair	
	int bufpos  = 0;
	
	for(int i = 0; i < numsSize; ++i)
	 {
		for (int j = i+1; j < numsSize; ++j)
		{
			if (nums[i] + nums[j] == target)
			{
				buf[bufpos] = i;
				++bufpos;
				buf[bufpos] = j;
				++bufpos;
				//get values into the array
				buf2 = calloc(bufl, sizeof(int));
				copyIArr(buf, buf2, bufl);
				bufl = bufl + 2;				
				buf = reallocarray(buf, bufl, sizeof(int));
				copyIArr(buf2, buf, bufl-2);
				/**
				 *copy the array the array into a buffer,
				 *agrandize the buffer, and copy it back
				 */
				free(buf2);

				retSz = retSz + 2;
			}
		}
	}
	*returnSize = retSz;
	//change for a malloced array
	return (buf);
}

void copyIArr(int src[], int tar[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		tar[i] = src[i];
	}
}
