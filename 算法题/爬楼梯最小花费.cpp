//数组的每个索引做为一个阶梯,第 i个阶梯对应着一个非负数的体力花费值cost[i](索引从0开始)。
//每当你爬上一个阶梯你都要花费对应的体力花费值,然后你可以选择继续爬一个阶梯或者爬两个阶梯。
//您需要找到达到楼层顶部的最低花费。在开始时,你可以选择从索引为0或1的元素作为初始阶梯。
#include <stdio.h>
int GetLowestCost(int n, int Cost[20])
{
	int choose, j , t1, t2, sum;//choose为继续爬的楼梯数
	while(n - choose > 0)
	{
		printf("请输入继续爬的楼梯数（1或2）：");
		scanf("%d",&choose); 
		if(choose == 1)
		{
			for(j = 0; j < n; j++)
			{
				if(Cost[j] < Cost[j + 1])
					t1 = Cost[j];
			}
			sum += t1;
		}
		if(choose == 2)
		{
			for(j = 0; j < n; j++)
			{
				if(Cost[j] < Cost[j + 1])
					t1 = Cost[j];
				if(t1 < Cost[j]);
					t2 = Cost[j];
			}
			sum += (t1 + t2);
		}
		choose += choose;
		printf("%d",choose);
	}
	return sum;
}
main()
{
	int cost[20], i, n, lowestCost;
	printf("请输入阶梯数：");
	scanf("%d",&n);
	printf("请输入每个阶梯所对应的花费：");
	for(i = 0; i < n; i++)
		scanf("%d",&cost[i]);
	lowestCost = GetLowestCost(n, cost);
	printf("爬上楼顶所需的最小花费为:%d",lowestCost);
}
