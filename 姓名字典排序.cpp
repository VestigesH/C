#include <stdio.h>
#include <string.h>
#define N 10

int main()
{
	char Name[N][20], temp[20];
	int i, j, k;
	printf("请输入十个姓名：\n");
	for(i = 0; i < N; i++)
		scanf("%s", Name[i]);
	for(i = 0; i < N - 1; i++)
	{
		k = i;
		for(j = i + 1; j < N; j++)
		{
			if(strcmp(Name[j], Name[k]) < 0)
				k = j;
			strcpy(temp, Name[i]);
			strcpy(Name[i], Name[k]);
			strcpy(Name[k], temp);
		}
	}
	printf("\n");
	printf("排序后的姓名为：\n");
	for(i = 0; i < N; i++)
		printf("%s\n",Name[i]);
	return 0;
} 
