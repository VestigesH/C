//��дһ�������жϴӼ�������������������Ժ���ż��
#include <stdio.h>
int main()
{
	int x;
	printf("������Ҫ�жϵ�������");
	scanf("%d",&x);
	if(x>0)
	{
		printf("%d������",x);
	}
	else if(x<0)
	{
		printf("%d�Ǹ���",x);
	}
	else
		printf("%d�Ȳ�������Ҳ���Ǹ���",x);
	printf("\n");
	if(x%2==0)
		printf("%d��ż��",x);
	else 
		printf("%d������",x);
	return 0;	
} 
