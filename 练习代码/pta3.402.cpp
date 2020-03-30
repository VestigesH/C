#include <stdio.h>
main()
{
	double x, y;
	scanf("%lf",&x);
	if( x == 10)
		y = 1 / x;
	else
		y = x;
	printf("f(%.1lf) = %.1lf",x ,y);
}
