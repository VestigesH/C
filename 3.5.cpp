//编写程序，输入四个值，并求它们的平均数
#include <stdio.h>
int main()
{
	float a,b,c,d,ave;
	printf("请输入这四个数：");
	scanf("%f %f %f %f",&a,&b,&c,&d);
	ave=(a+b+c+d)/4;
	printf("他们的平均数是%f",ave);
	return 0;
} 
