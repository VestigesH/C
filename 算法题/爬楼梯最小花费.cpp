//�����ÿ��������Ϊһ������,�� i�����ݶ�Ӧ��һ���Ǹ�������������ֵcost[i](������0��ʼ)��
//ÿ��������һ�������㶼Ҫ���Ѷ�Ӧ����������ֵ,Ȼ�������ѡ�������һ�����ݻ������������ݡ�
//����Ҫ�ҵ��ﵽ¥�㶥������ͻ��ѡ��ڿ�ʼʱ,�����ѡ�������Ϊ0��1��Ԫ����Ϊ��ʼ���ݡ�
//	����ȫ�ֱ���ccount��¼���鳤��
//	ccount = 3 ʱΪ������� 
//	ccount > 3 ʱ���� 
//	���鳤�ȴ��� 3 �жϴ�cost[0]��ʼ���Ǵ� cost[1]��ʼ 
//	Ȼ�������ж�cost[i]�ĺ�����Ԫ�صĴ�С 
#include<stdio.h>
#define N 10
int ccount = 0;
int s;
int put(int cost[])
{
	if(ccount == 3)               //���鳤��Ϊ3ʱΪ������� 
	{
		if((cost[0] + cost[2]) > cost[1]) 
		{
			s = cost[1];
			return s;
		}  
		else 
		{
			s = cost[0] + cost[2];
			return s;
		}
	}
	else
	{
		if(cost[0] > cost[1])       //���鳤�ȴ��� 3 �жϴ�cost[0]��ʼ���Ǵ� cost[1]��ʼ 
		{
			s = cost[1];
			search(cost,1);
		}
		else
		{
			s = cost[0];
			search(cost,0);
		}		
	}	
}

int search(int cost[],int i)    //�����ж�cost[i]�ĺ�����Ԫ�صĴ�С 
{
	if(i == ccount - 2 || i == ccount - 1)
	{
		return s; 
	}
	else 
	{
		if(cost[i + 2] <= cost[i + 1])
		{
			s += cost[i + 2] ;
			search(cost, i + 2);
		}
		else
		{
			s += cost[i + 1];
			search(cost, i + 1);
		}		
	}
}
void main()
{
	int cost[N];
	int i = 0;
	printf("�������������������е�Ԫ��(��-1��������):");
	do
	{
		scanf("%d",&cost[i++]);
		ccount++;
	}while(cost[i - 1] != -1);
	ccount--;
	printf("ccount = %d\n",ccount);
	put(cost);
	printf("��С����Ϊ:%d",s);
}
