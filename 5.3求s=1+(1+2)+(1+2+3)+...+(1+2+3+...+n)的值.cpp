//��дһ��������s=1+(1+2)+(1+2+3)+......+(1+2+3+.....+n)��ֵ
#include <stdio.h>
int main()
{
	int n,i=1,t=0,sum=0;
	printf("������n��");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		t += i;
		sum += t;
	}
	printf("������Ϊ��%d",sum);
} 


