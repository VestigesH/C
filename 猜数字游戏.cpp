#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int data,guess;
	srand((unsigned)time(NULL));
	data=rand()%5+1;
	printf("������Ҫ�µ����֣���1-5):");
	scanf("%d",&guess);
	if (guess==data)
		printf("�¶��ˣ���ȷ����Ϊ%d!\n",data);
	else
		printf("�´��ˣ���ȷ����Ϊ%d!\n",data);
}
