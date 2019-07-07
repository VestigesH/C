#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arr[5];
	int i,max,min;
	printf("请输入五个整数: ");
	fflush(stdout);
	for (i=0;i<5;i++) 
	{
		scanf("%d",&arr[i]);
	}
	printf("数组元素为: \n");
	for (i=0;i<5;i++) printf("%d ",arr[i]);
	max=min=arr[0];
	for (i=0;i<=4;i++)
	{
		if(max<arr[i]) max=arr[i];
		else if(min>arr[i]) min=arr[i];
	}
	printf("\n");
	printf("最大值为: %d\n最小值为: %d\n",max,min);
}
