#include <stdio.h>
int main()
{
	int Num[100], n, i, left, right, t ;
	printf("�����������е�����Ԫ�ظ�����");
	scanf("%d", &n);
	printf("�����������е�����Ԫ�أ�");
	for(i = 0 ; i < n ; i++)
		scanf("%d", &Num[i]);
	printf("ԭ����Ϊ��");
	for(i = 0 ; i < n ; i++)
		printf(" %d", Num[i]);
	left = 0;
	right = n-1;
	for(i = 0 ; i < n / 2 ; i++)
	{
		t = Num[left];
		Num[left] = Num[right];
		Num[right] = t;
		left++;
		right--;
	}
	printf("\n�����ת֮�������Ϊ��");
	for(i = 0 ; i < n ; i++)
		printf(" %d", Num[i]);
}
