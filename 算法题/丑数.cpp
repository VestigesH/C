//��дһ�������жϸ��������Ƿ�Ϊ��������������ֻ����������2, 3, 5����������
#include <stdio.h>
main()
{
	int n;
	printf("��������Ҫ�жϵ����֣�");
	scanf("%d",&n); 
	if(n > 1)
	{
		while(n % 2 == 0)
			n /= 2;
		while(n % 3 == 0)
			n /= 3;
		while(n % 5 == 0)
			n /= 5;
		if(n == 1)
			printf("True");
		else
			printf("False");
	}
	else
		printf("False");
}
