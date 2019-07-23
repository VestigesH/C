#include <stdio.h>
int main()
{
	int n,sum=0;
	n=1;
	while(n<=200)
	{
		sum=sum+n;
		n++;	
	}
	printf("sum=%d\n",sum);
}
