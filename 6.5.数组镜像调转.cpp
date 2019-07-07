#include <stdio.h>
int main()
{
	int Num[100], n, i, left, right, t ;
	printf("请输入数组中的数字元素个数：");
	scanf("%d", &n);
	printf("请输入数组中的数字元素：");
	for(i = 0 ; i < n ; i++)
		scanf("%d", &Num[i]);
	printf("原数组为：");
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
	printf("\n镜像调转之后的数组为：");
	for(i = 0 ; i < n ; i++)
		printf(" %d", Num[i]);
}
