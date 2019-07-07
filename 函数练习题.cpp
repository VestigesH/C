#include <stdio.h>
int m=13;
fun (int x,int y)
{
	int m=3;
	return(x*y-m);
}
int main()
{
	int a=7,b=5;
	printf("%d\n",fun(a,b)/m);
}
