//����һ���������飬���������ҳ�����������ɵ����˻������������˻���
#include <stdio.h>
main()
{
	int Num[10];
	int i, n , j,t ,product = 1;
	printf("������������Ԫ�ظ�����");
	scanf("%d",&n);
	printf("�����������е�Ԫ�أ�");
	for(i = 0; i < n; i++)
		scanf("%d",&Num[i]);
	for(i = 0; i < n-1; i++)
	{
		for(j = 0; j < n-i; j++)
		{
			if(Num[j] < Num[j + 1])
			{
				t = Num[j];
				Num[j] = Num[j + 1];
				Num[j + 1] = t;
			}
		}
	}
	for(i = 0; i < 3; i++)
		product *= Num[i];
	printf("���˻�Ϊ��%d",product);
} 

