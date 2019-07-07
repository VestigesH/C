#include <stdio.h>
int main()
{
	int n=1,sum=0;	
	while (n<=200)
	{
		sum=sum+n;
		n++;
	}
	printf("sum=%d\n",sum);
} 
