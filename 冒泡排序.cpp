#include <stdio.h>
Sort (int A[10],int n)//n为要排序的个数 
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
	printf("请输入10个数字：");
	for(i=0;i<10;i++)
		scanf("%d",&B[i]);
	Sort(B,10);
	printf("排序后的数组为：");
	for(i=0;i<10;i++)
	{
		printf("%4d",B[i]);
	}
} 
