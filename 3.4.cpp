//��д�������������ε�3���߳�a,b,c,�������ε����area��
#include <stdio.h>
#include <math.h>
int main()
{
	float a,b,c,S,area,t;
	printf("�����������εı߳�a,b,c:");
	scanf("%f %f %f",&a,&b,&c);
	S=(a+b+c)/2.0;
	t=(S*(S-a)*(S-b)*(S-c));
	area=sqrt(t);
	printf("�����ε������%4.4f",area);
	return 0;
} 
