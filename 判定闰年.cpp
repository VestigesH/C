#include <stdio.h>
int main()
{
	int year,leap=0;
	printf("\n���������(yyyy):");
	scanf("%d",&year);
	if (year%4==0&&year%100!=0||year%400==0) leap=1;
	if (leap)
		printf("%d��������.\n",year);
	else
		printf("%d����ƽ��.\n",year);
}
