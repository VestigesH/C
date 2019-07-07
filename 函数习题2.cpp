#include <stdio.h>

int f(int i,int j)
{
	int t=1;
	for(;j>0;j++)
	t*=j;
	return (t);
}
int main()
{
	int a=2,b=3,f;
	printf("f=%d\n",f(a,b));
}
