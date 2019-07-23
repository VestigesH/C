//编写一个程序，判断从键盘输入的整数的正负性和奇偶性
#include <stdio.h>
int main()
{
	int x;
	printf("请输入要判断的整数：");
	scanf("%d",&x);
	if(x>0)
	{
		printf("%d是正数",x);
	}
	else if(x<0)
	{
		printf("%d是负数",x);
	}
	else
		printf("%d既不是正数也不是负数",x);
	printf("\n");
	if(x%2==0)
		printf("%d是偶数",x);
	else 
		printf("%d是奇数",x);
	return 0;	
} 
