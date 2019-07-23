//编写一个程序，输出300内所有的素数，每10个一行
#include <stdio.h>
int main()
{
	int counter=0;
	int n,i;
	for(n=2;n<300;n++)
	{
		for(i=2;i<n;i++)
		{
			if (n%i==0)
			break;
		}
		if (i>=n)
		{
			counter=counter+1;
			printf("%5d",n);
			if(counter%10==0)
			{
				printf("\n");
			}
		}	
	}
}
