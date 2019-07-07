#include<stdio.h> 
int main(void)
{
	int i=1;
	int sum;
	sum=++i + i++;
	printf("%d,%d",sum,i);
	return 0;
}
