//编写一个程序，求s=1+(1+2)+(1+2+3)+......+(1+2+3+.....+n)的值
#include <stdio.h>
int main()
{
	int n,i=1,t=0,sum=0;
	printf("请输入n：");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		t += i;
		sum += t;
	}
	printf("计算结果为：%d",sum);
} 


