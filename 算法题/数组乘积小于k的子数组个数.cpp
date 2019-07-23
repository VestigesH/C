#include <stdio.h>
#include <stdlib.h>
#define N 10
int count = 0;   //count 记录子数组个数
int ncount = 0;  //ncount记录数组长度，
int search(int nums[])
{
	int *p;
	int k, i, j, s;
	p = nums;
	printf("请输入k:");
	scanf("%d",&k);
	for(i = 0; i < ncount; i++)
	{
		if( *(p + i) < k)   
			count++;
		s = *(p + i);
		for(j = 1; j < ncount - i; j++)
		{
			s *= *(p + j);
			if(s < k)   
				count++; 
		}	
	}
	return count;	
}
void main()
{
	int nums[N];
	int i = 0;
	printf("请输入数组中的所有元素(以输入-1结束):");
	do
	{
		scanf("%d",&nums[i++]);
		ncount++;
	}while(nums[i - 1] != -1);
	ncount--;
	search(nums);
	printf("%d",count);
}
