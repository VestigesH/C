#include <stdio.h>
#define N 5
main()
{
	int Num[N], i, j, t1, t2;
	printf("请输入数组中的数据：");
	for(i = 0; i< N; i++)
		scanf("%d",&Num[i]);
	for(i = 0; i < N; i++)
	{
		t1 = i;
		for(j = i + 1; j < N; j++)
		{
			if(Num[t1] > Num [j])
				t1 = j;
		} 
		t2 = Num[i];
		Num[i] = Num[t1];
		Num[t1] =  t2;
	}
	printf("排序后的数字为：");
	for(i = 0; i < N; i++)
		printf("%4d",Num[i]);
}
