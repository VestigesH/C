#include <stdio.h>
Sort (int A[10],int n)//nΪҪ����ĸ��� 
{
	int i,j,t;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(A[j]<A[j+1])
			{
				t=A[j];
				A[j]=A[j+1];
				A[j+1]=t;
			}
		}
	}
}

int main()
{
	int B[10],i;
	printf("������10�����֣�");
	for(i=0;i<10;i++)
		scanf("%d",&B[i]);
	Sort(B,10);
	printf("����������Ϊ��");
	for(i=0;i<10;i++)
	{
		printf("%4d",B[i]);
	}
} 
