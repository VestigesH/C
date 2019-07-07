#include <stdio.h>
#include "stdlib.h"
int main()
{
	int i, j, k, count, num;
	int a[100][100], b[100][100], c[100][100];
	num = 0;
	count = 0;
	for(i = 0; i < 100; i++)
	{
		for(j = 0; j < 100; j++)
			c[i][j]=0;
	}
	printf("请输入您所需运算的行列数:");
	scanf("%d",&num);
	printf("请输入矩阵A的数字\n");
	for(i = 0; i < num; i++)
	{
		for(j = 0; j < num; j++)
		{
			scanf("%d",&a[i][j]);
			count++;
			if(count % num == 0)
				printf("\n");
		}
	}
	printf("\n请输入矩阵B的数字\n");
	for(i = 0; i < num; i++)
	{
		for(j = 0; j < num; j++)
		{
			scanf("%d",&b[i][j]);
			count++;
			if(count % num==0)
				printf("\n");
		}
	}
	for(i = 0; i < num; i++)
	{
		for(j = 0; j < num; j++)
		{
			for(k = 0; k < num; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	printf("结果为:\t\t");
	for(i = 0; i < num; i++)
	{
		for(j = 0; j < num; j++)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n\t\t");
	}
	return 0;
}
