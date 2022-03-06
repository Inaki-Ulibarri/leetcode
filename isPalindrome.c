#include <stdio.h>
#include <stdbool.h>

bool isPalin(int x);

int main()
    {
    int a = 123,
	b = 121,
	c = 12,
	d = 11;
    
    if(isPalin(a))
	puts("123 is a palindrom");

    if (isPalin(b))
	puts("121 is a palindrom");

    if (isPalin(c))
	puts("12 is a palindrom");

    if (isPalin(d))
	puts("11 is a palindrom");

    return (0);

    }

bool isPalin(int x)
    {
    if (x < 0)
	return (false);
    int rev = 0,
	rem = 0,
	cpy = x;
    while (x != 0)
	{
	rem = x % 10;
	rev = rev * 10 + rem;
	x /= 10;
	}
    return (cpy == rev);
    }
 
