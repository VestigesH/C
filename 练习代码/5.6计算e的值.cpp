//��дһ��������e��ֵ����ͨ��С��10��-7�η�ֹͣ����  e=1+1/1!+1/2!+1/3!+....+1/n!
#include <stdio.h>
int main()
{
	int n=1;
	double t=1,sum=1; 
	while((1.0/t)>=1e-7)
	{
		t*=n;
		sum +=1.0/t;
		n++;
	}	
	printf("%lf",sum);
}

