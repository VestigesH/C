#include <stdio.h>
int main()
{
	int i=1;
	double fac=1;
	while (i<=100)
	{
		fac*=i;
		i++;
	}
	printf("1*2*3*4*...*100=%lf",fac);
}
