#include <stdio.h>
int main()
{
	int number;
	printf("\n请输入一个整数:");
	scanf("%d",&number);
	if (number%2==0)
		printf("\n整数%d是一个偶数。",number);
	else
		printf("\n整数%d是一个奇数。",number);		 
}
