#include <stdio.h>
#define N 5
main()
{
	int Num[N], i, j, t;
	printf("�����������е����֣�");
	for(i = 0; i < N; i++)
		scanf("%d",&Num[i]);
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < i; j++)
		{
			if(Num[i] > Num[j])
			{
				t = Num[i];	
				Num[i] = Num[j];
				Num[j] = t;
			}
		}
	}
	for(i = 0; i < N; i++)
		printf("%4d",Num[i]); 
}
