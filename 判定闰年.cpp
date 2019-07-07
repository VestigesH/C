#include <stdio.h>
int main()
{
	int year,leap=0;
	printf("\n请输入年份(yyyy):");
	scanf("%d",&year);
	if (year%4==0&&year%100!=0||year%400==0) leap=1;
	if (leap)
		printf("%d年是闰年.\n",year);
	else
		printf("%d年是平年.\n",year);
}
