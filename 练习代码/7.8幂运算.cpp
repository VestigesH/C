#include <stdio.h>
void GetMi()
{
	int n, x, i;
	long result = 1;
	printf("������Ҫ����������ĵ�����ָ����");
	scanf("%d %d",&x, &n);
	if (x < 0)
		printf("��������ȷ�ĵ����������㣡");
	else if(n == 1)
	{
		result == 1;
		printf("��������1");
	}
	else
	{
		for(i = 1; i <= n; i++)
			result *= x;
		printf("��������%ld",result);
	}
}
int main()
{
	GetMi();
} 
