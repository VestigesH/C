//给定两个数组，编写一个函数来计算它们的交集。
#include <stdio.h>
void GetJiao(int Nums1[] ,int Nums2[],int n1,int n2)
{
	int i, j;
	printf("两个数组的交集为："); 
	for(i = 0; i < n1; i++)
	{
		for(j = 0; j < n2; j++)
		{
			if(Nums1[ i ] == Nums2[ j ])
				printf("%4d",Nums1[i]);
		}
	}	
}
main()
{
	int i, N1[10], N2[10], l1, l2;
	printf("请输入第一个数组的元素个数：");
	scanf("%d",&l1);
	printf("请输入第一个数组的元素：");
	for(i = 0; i < l1; i++)
		scanf("%d",&N1[i]);
	printf("请输入第二个数组的元素个数：");
	scanf("%d",&l2);
	printf("请输入第二个数组的元素：");	
	for(i = 0; i < l2; i++)
		scanf("%d",&N2[i]);
	GetJiao(N1 ,N2, l1, l2);
} 
