#include <stdio.h>
int main()
{
	int i,j;
	double t,sum;
	sum=0;
	for (i=1;i<=100;i++)
	{
		t=1;
		for (j=1;j<=100;j++)
		t*=j;
		sum+=t;
	}
	printf("1!+2!+...+100!=%lf",sum); 
}
