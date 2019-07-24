//数组的每个索引做为一个阶梯,第 i个阶梯对应着一个非负数的体力花费值cost[i](索引从0开始)。
//每当你爬上一个阶梯你都要花费对应的体力花费值,然后你可以选择继续爬一个阶梯或者爬两个阶梯。
//您需要找到达到楼层顶部的最低花费。在开始时,你可以选择从索引为0或1的元素作为初始阶梯。
//	定义全局变量ccount记录数组长度
//	ccount = 3 时为特殊情况 
//	ccount > 3 时递推 
//	数组长度大于 3 判断从cost[0]开始还是从 cost[1]开始 
//	然后依次判断cost[i]的后两个元素的大小 
#include<stdio.h>
#define N 10
int ccount = 0;
int s;
int put(int cost[])
{
	if(ccount == 3)               //数组长度为3时为特殊情况 
	{
		if((cost[0] + cost[2]) > cost[1]) 
		{
			s = cost[1];
			return s;
		}  
		else 
		{
			s = cost[0] + cost[2];
			return s;
		}
	}
	else
	{
		if(cost[0] > cost[1])       //数组长度大于 3 判断从cost[0]开始还是从 cost[1]开始 
		{
			s = cost[1];
			search(cost,1);
		}
		else
		{
			s = cost[0];
			search(cost,0);
		}		
	}	
}

int search(int cost[],int i)    //依次判断cost[i]的后两个元素的大小 
{
	if(i == ccount - 2 || i == ccount - 1)
	{
		return s; 
	}
	else 
	{
		if(cost[i + 2] <= cost[i + 1])
		{
			s += cost[i + 2] ;
			search(cost, i + 2);
		}
		else
		{
			s += cost[i + 1];
			search(cost, i + 1);
		}		
	}
}
void main()
{
	int cost[N];
	int i = 0;
	printf("请输入体力花费数组中的元素(以-1结束输入):");
	do
	{
		scanf("%d",&cost[i++]);
		ccount++;
	}while(cost[i - 1] != -1);
	ccount--;
	printf("ccount = %d\n",ccount);
	put(cost);
	printf("最小花费为:%d",s);
}
