#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main()
{
	int NumA[20], num, i, j, len, count, t;
	len=0;
	count =0;
	char c = 0;
	printf("��������������(����)�ĳ���:");
	scanf("%d",&len);
	printf("��������������(����):");
	for(i = 0 ; i < len ; i++)
		scanf("%d", &NumA[i]);
	do
	{
		count++;
		printf("\n����������Ҫ�������:");
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
		printf("\n�Ƿ�������룿������y(Y)����n(N):  ");
		c = getch();
		putch(c);
	}while(c == 'y' || c == 'Y');
	return 0;
}
