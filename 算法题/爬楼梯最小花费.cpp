//�����ÿ��������Ϊһ������,�� i�����ݶ�Ӧ��һ���Ǹ�������������ֵcost[i](������0��ʼ)��
//ÿ��������һ�������㶼Ҫ���Ѷ�Ӧ����������ֵ,Ȼ�������ѡ�������һ�����ݻ������������ݡ�
//����Ҫ�ҵ��ﵽ¥�㶥������ͻ��ѡ��ڿ�ʼʱ,�����ѡ�������Ϊ0��1��Ԫ����Ϊ��ʼ���ݡ�
#include <stdio.h>
int GetLowestCost(int n, int Cost[20])
{
	int choose, j , t1, t2, sum;//chooseΪ��������¥����
	while(n - choose > 0)
	{
		printf("�������������¥������1��2����");
		scanf("%d",&choose); 
		if(choose == 1)
		{
			for(j = 0; j < n; j++)
			{
				if(Cost[j] < Cost[j + 1])
					t1 = Cost[j];
			}
			sum += t1;
		}
		if(choose == 2)
		{
			for(j = 0; j < n; j++)
			{
				if(Cost[j] < Cost[j + 1])
					t1 = Cost[j];
				if(t1 < Cost[j]);
					t2 = Cost[j];
			}
			sum += (t1 + t2);
		}
		choose += choose;
		printf("%d",choose);
	}
	return sum;
}
main()
{
	int cost[20], i, n, lowestCost;
	printf("�������������");
	scanf("%d",&n);
	printf("������ÿ����������Ӧ�Ļ��ѣ�");
	for(i = 0; i < n; i++)
		scanf("%d",&cost[i]);
	lowestCost = GetLowestCost(n, cost);
	printf("����¥���������С����Ϊ:%d",lowestCost);
}
