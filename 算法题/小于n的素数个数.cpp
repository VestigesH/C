//ͳ������С�ڷǸ����� n ��������������
#include <stdio.h>
main()
{
	int n, i, j, counter = 0;
	printf("������Ǹ�����n��");
	scanf("%d",&n);
	for(i = 2; i < n; i++)
	{
		for(j = 2; j < i; j++)
		{
			if(i % j == 0)	break;	
		}
		if(i==j) counter++;
	}
	printf("%d",counter);
}

