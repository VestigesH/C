#include <stdio.h>
#include <math.h>
int main()
{
	float x,y;
	printf("\n«Î ‰»Îx:");
	scanf("%f",&x);
	if (x<10)      y=x+1;
	else if (x<20) y=pow(x,2);
	else           y=6*x+9;
	printf("y=%f\n",y);
}
