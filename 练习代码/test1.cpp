#include <stdio.h>
main()
{
	int i=1;
	double fac = 1;
	while (i <= 50)
	{
		fac *= i;
		i++;
		printf("%d! = %lf\n",i,fac);
	}
}
