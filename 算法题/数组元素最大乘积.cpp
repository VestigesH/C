//给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
#include <stdio.h>
main()
{
	int Num[10];
	int i, n , j,t ,product = 1;
	printf("请输入数组中元素个数：");
	scanf("%d",&n);
	printf("请输入数组中的元素：");
	for(i = 0; i < n; i++)
		scanf("%d",&Num[i]);
	for(i = 0; i < n-1; i++)
	{
		for(j = 0; j < n-i; j++)
		{
			if(Num[j] < Num[j + 1])
			{
				t = Num[j];
				Num[j] = Num[j + 1];
				Num[j + 1] = t;
			}
		}
	}
	for(i = 0; i < 3; i++)
		product *= Num[i];
	printf("最大乘积为：%d",product);
} 

