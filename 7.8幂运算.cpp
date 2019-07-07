#include <stdio.h>
void GetMi()
{
	int n, x, i;
	long result = 1;
	printf("请输入要进行幂运算的底数和指数：");
	scanf("%d %d",&x, &n);
	if (x < 0)
		printf("请输入正确的底数进行运算！");
	else if(n == 1)
	{
		result == 1;
		printf("运算结果是1");
	}
	else
	{
		for(i = 1; i <= n; i++)
			result *= x;
		printf("运算结果是%ld",result);
	}
}
int main()
{
	GetMi();
} 
