#include <stdio.h>

#define ARRSZ(a) (sizeof(a)/sizeof(a[0]))


int searchIns(int *nums, int size, int targ);

int main()
    {
	    int arr[] = {1,2,3,10};
    int ret = searchIns(arr, ARRSZ(arr), 10);
    printf("ret: %d\n", ret);

    return (0);
    }

int searchIns(int *nums, int size, int targ)
    {
    if (targ <= nums[0])
        return (0);
    else if (targ > nums[size-1])
	return (size);
    
    int mid = size/2,
	bot = 0,
	top = size-1;

    for (int i = 1; i < size; ++i)
	{
	if (nums[mid] == targ)
	    return (mid);

	else if(!(nums[bot] < nums[mid] &&
		nums[mid] < nums[top]))
		return (top);

	if (nums[mid] < targ)
	    {
	    bot = mid;
	    mid = (bot+top)/2;
	    }
	else
	    {
	    top = mid;
	    mid = (bot+top)/2;
	    }
	}
    
    return (-1);
    }
