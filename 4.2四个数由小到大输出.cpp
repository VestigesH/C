//编写四个整数a,b,c,和d,把这四个数由小到大输出
#include <stdio.h>
int main()
{
	int a,b,c,d,t;
	printf("请输入a,b,c,d:");
	scanf("%d %d %d %d",&a,&b,&c,&d);
	if (a > b)
	{
		t = a;
		a = b;
		b = t;
	}
	if (a > c)
	{
		t = a;
		a = c;
		c = t;
	}
	if (a > d)	
	{
		t = a;
		a = d;
		d = t;
	}
	if (b > c)
	{
		t = b;
		b = c;
		c = t;
	}
	if (b > d)
	{
		t = b;
		b = d;
		d = t;
	}
	if (c > d)
	{
		t = c;
		c = d;
		d = t;
	}
	printf("这四个数由小到大输出为:%d %d %d %d\n",a,b,c,d);
	return 0;
} 
