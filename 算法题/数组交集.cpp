////�����������飬��дһ���������������ǵĽ�����
#include <stdio.h>
void GetJiao(int Nums1[] ,int Nums2[],int n1,int n2)
{
	int i , j , k = 0;
	int nums3[20];
	printf("��������Ľ���Ϊ��"); 
	for(i = 0; i < n1; i++)
	{
		for(j = 0; j < n2; j++)
		{
			if(Nums1[ i ] == Nums2[ j ])
			{
				nums3[ k ] = Nums1[i];	
				k++;
			}
		}
	}
	for(i = 0; i < k; i++)
	{
		if(nums3[0] != nums3[i + 1])
			printf("%4d",nums3[i]);
		else
			break; 
	} 	
}
main()
{
	int i, N1[10], N2[10], l1, l2;
	printf("�������һ�������Ԫ�ظ�����");
	scanf("%d",&l1);
	printf("�������һ�������Ԫ�أ�");
	for(i = 0; i < l1; i++)
		scanf("%d",&N1[i]);
	printf("������ڶ��������Ԫ�ظ�����");
	scanf("%d",&l2);
	printf("������ڶ��������Ԫ�أ�");	
	for(i = 0; i < l2; i++)
		scanf("%d",&N2[i]);
	GetJiao(N1 ,N2, l1, l2);
} 
