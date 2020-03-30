#include <stdio.h>
#include <math.h>
long int fac(unsigned int n)
{
	long int f;
	if(n == 0)
		return 1;
	f = fac(n - 1) * n;
	return f;
}
main()
{
	unsigned int n;
	printf("input a unsigned number:");
	scanf("%u",&n);
	printf("%u! = %10ld",n , fac(n));
} 
