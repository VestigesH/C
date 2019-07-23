#include <stdio.h>
fun(int *a,int b[])
{
	b[0]=*a+6; 
}
int main()
{
	int a,b[5];
	a=0;b[0]=4;
	fun(&a,b);
	printf("%d\n",b[0]);
}
