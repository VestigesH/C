#include<stdio.h>
#include<math.h>
int main(void)
{
	double x,y,e;
	e=2.71828;
	printf("please input x:\n");
	scanf("%lf",&x);
	if(x>=0 && x<20)
	{
		y=5*x+11;
	}
	if(x>=20 && x<40)
	{
		y=sin(x)+cos(x);
	}
	if(x>=40 && x<60)
	{
		y=pow(e,x)-1;
	}
	if(x>=60 && x<80)
	{
		y=log(x+1);
	}
	else
	{
		y=0;
	}
	printf("%lf",y);
	return 0;
}
