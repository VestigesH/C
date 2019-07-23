//6.5将整型数组中的所有元素镜像对调，第一个与最后一个对调，第二个与倒数第二个对调，将对调后的结果输出。
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
