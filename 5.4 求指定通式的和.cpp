//��дһ��������1-1/2+1/3-1/4+...+1/99-1/100��ֵ
#include <stdio.h>
int main()
{
	int i=1,t=1; 
	double sum;
	for(i=1;i<=100;i++)
	{
		sum += t*(1.0/i);
		t = -t;
	}
	printf("������Ϊ %lf",sum);
} 
