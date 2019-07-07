#include <stdio.h>
int main()
{
	int year, month, wDay, leap, fDay;
	int  i, d, y;
	int Days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	printf("please input the year :");
	scanf("%d", &year);
	printf("please input the month :");
	scanf("%d", &month);
	y = year;
	wDay = 5 * (y/ 4) + (y % 4) - (y / 100) + (y /400);//蔡勒公式判断输入日期是一年中的第几天
	leap = ((year % 4 == 0 && year% 100 != 0)||(year % 400 == 0) ? 1 : 0);//判断年份是否为闰年
	Days[2] = (leap == 1) ? 29 : 28;//二月的天数
	for(i = 0, d = 0; i < month ; i++)
	{
		d += Days[i];
	}
	fDay = ( d + wDay) % 7;//此月第一天是周几
	printf("\t\t 年份: %d 年   月份: %d 月   ", year,month);
	printf("\n   Sun     Mon      Tue      Wed     Thu     Fri    Sat	\n");
	if(leap==1)
	{
		for( i = 0; i < fDay-1; i++)  //如果这周的第一天不是星期天，打印空格
		{
			printf("%7c ",' ');
		}
	}
	else
	{
		for( i = 0; i < fDay; i++)  //如果这周的第一天不是星期天，打印空格
		{
			printf("%7c ",' ');
		}
	}
	for( d = 1; d <= Days[month]; d++)
	{
		printf("%7d ",d);
		if((( d+fDay ) % 7 == 0) && d <Days[month])
			printf("\n");
	}

}