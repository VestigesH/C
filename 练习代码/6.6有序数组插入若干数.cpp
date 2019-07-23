#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main()
{
	int NumA[20], num, i, j, len, count, t;
	len=0;
	count =0;
	char c = 0;
	printf("请输入有序数组(降序)的长度:");
	scanf("%d",&len);
	printf("请输入有序数组(降序):");
	for(i = 0 ; i < len ; i++)
		scanf("%d", &NumA[i]);
	do
	{
		count++;
		printf("\n请您输入您要插入的数:");
		scanf("%d",&num);
		NumA[len + count] = num;
    	for(i = 0; i<= (len+count); i++)
		{
			for(j = i + 1; j <= (len+1+count);  j++)
			{
				if(NumA[i] < NumA[j])
				{
					t = NumA[i] ;
					NumA[i] = NumA[j];
					NumA[j] = t;
				}
			}
		}
			for(i = 0 ; i < count+len; i++)
		printf("%d ",NumA[i]);
		printf("\n是否继续插入？请输入y(Y)或者n(N):  ");
		c = getch();
		putch(c);
	}while(c == 'y' || c == 'Y');
	return 0;
}
