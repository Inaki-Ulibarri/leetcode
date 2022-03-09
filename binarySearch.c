#include <stdio.h>

#define ARRSZ(a) (sizeof(a)/sizeof(a[0]))


int search(int *nums, int size, int targ);

int main()
    {
    int arr[] = {1,3,5};
    int ret = search(arr, ARRSZ(arr), 2);
    printf("ret: %d\n", ret);

    return (0);
    }

int search(int *nums, int size, int targ)
    {
    if (targ == nums[0])
        return (0);
    
    int mid = size/2,
	bot = 0,
	top = size;
    for (int i = 1; i < size; ++i)
	{
	if (nums[mid] == targ)
	    return (mid);
	else if (nums[mid-1] == targ)
	    return (mid-1);

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
a
