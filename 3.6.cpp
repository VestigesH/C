//从键盘输入一个整数，分别输出它的个位数，十位数和百位数。
#include <stdio.h>
int main()
{
	int x,g,s,b;
	printf("请输入这个整数：");
	scanf("%d",&x);
	if(x<1000 && x>99)
	{
		g = x %10;
		s = x%100/10;
		b = x/100;
	}
	else if(x<100 && x>9)
	{
		b = 0;
		s = x/10;
		g = x%10;
	}	
	printf("这个整数的个位,十位,百位分别是%d %d %d",g,s,b);
	return 0;
} 
