//�Ӽ�������һ���������ֱ�������ĸ�λ����ʮλ���Ͱ�λ����
#include <stdio.h>
int main()
{
	int x,g,s,b;
	printf("���������������");
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
	printf("��������ĸ�λ,ʮλ,��λ�ֱ���%d %d %d",g,s,b);
	return 0;
} 
