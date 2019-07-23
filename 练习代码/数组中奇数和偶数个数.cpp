#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arr[]={1,2,3,4,5,6,8};
	int i,js=0,os=0;
	int len =sizeof(arr)/sizeof(int);
	printf("数组元素为: \n");
	for (i=0;i<len;i++)
	{
		if (arr[i]%2==0) os+=1;
		else js+=1;
		printf("%d ",arr[i]);
	}
	printf("\n偶数个数为:%d\n奇数个数为:%d",os,js);
}
