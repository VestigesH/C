#include <stdio.h>
#include <math.h>
int main()
{
	double x,y;
	double e=2.7;
	printf("请输入x:");
	scanf("%lf",&x);
	if(x>=0 && x<20)
	{
		y=5*x+1;
	}
	else if(x>=20 && x<40)
	{
		y=sin(x)+cos(x);
	}
	else if(x>=40 && x<60)
	{
		y=pow(e,x)-1;	
	}
	else if(x>=60 &&x<80)
	{
		y=log(x+1);	
	}
	else 
	{
		y=0;	
	}
	printf("计算结果为%lf",y);
	return 0;	
}
