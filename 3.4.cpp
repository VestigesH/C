//编写程序，输入三角形的3个边长a,b,c,求三角形的面积area。
#include <stdio.h>
#include <math.h>
int main()
{
	float a,b,c,S,area,t;
	printf("请输入三角形的边长a,b,c:");
	scanf("%f %f %f",&a,&b,&c);
	S=(a+b+c)/2.0;
	t=(S*(S-a)*(S-b)*(S-c));
	area=sqrt(t);
	printf("三角形的面积是%4.4f",area);
	return 0;
} 
