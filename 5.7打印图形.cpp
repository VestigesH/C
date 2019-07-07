#include <stdio.h>
int main()
{
	int i,j,n;
	printf("请输入要打印的行数n:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf(" ");
		}
		for(j=1;j<=8-i;j++)
		{
			printf("*");
		}
		printf("\n"); 		
	}
} 
