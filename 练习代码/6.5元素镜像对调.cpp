//6.5�����������е�����Ԫ�ؾ���Ե�����һ�������һ���Ե����ڶ����뵹���ڶ����Ե������Ե���Ľ�������
#include <stdio.h>
int main()
{
	int i,t; 
	int nums[10]={1,2,3,4,5,6,7,8,9,10};
	for(i=0;i<5;i++)
	{
		t=nums[i];
		nums[i]=nums[9-i];
		nums[9-i]=t;
	}
	for(i=0;i<10;i++)
	{
		printf("%4d",nums[i]);
	}
} 
