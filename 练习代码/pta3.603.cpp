#include <stdio.h>
#include <math.h>
main()
{
	double a, b, c, area, perimeter, s;
	scanf("%lf %lf %lf", &a, &b, &c);
	s = (a + b + c) / 2;
	perimeter = a + b + c;
	if(a + b > c && a + c > b && b + c > a)
	{
		area = sqrt(s * (s - a) * (s - b) * (s - c));
		printf("area = %.2lf; perimeter = %.2lf",area , perimeter);
	}
	else
		printf("These sides do not correspond to a valid triangle");
 } 
