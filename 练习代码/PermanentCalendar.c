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
	wDay = 5 * (y/ 4) + (y % 4) - (y / 100) + (y /400);//���չ�ʽ�ж�����������һ���еĵڼ���
	leap = ((year % 4 == 0 && year% 100 != 0)||(year % 400 == 0) ? 1 : 0);//�ж�����Ƿ�Ϊ����
	Days[2] = (leap == 1) ? 29 : 28;//���µ�����
	for(i = 0, d = 0; i < month ; i++)
	{
		d += Days[i];
	}
	fDay = ( d + wDay) % 7;//���µ�һ�����ܼ�
	printf("\t\t ���: %d ��   �·�: %d ��   ", year,month);
	printf("\n   Sun     Mon      Tue      Wed     Thu     Fri    Sat	\n");
	if(leap==1)
	{
		for( i = 0; i < fDay-1; i++)  //������ܵĵ�һ�첻�������죬��ӡ�ո�
		{
			printf("%7c ",' ');
		}
	}
	else
	{
		for( i = 0; i < fDay; i++)  //������ܵĵ�һ�첻�������죬��ӡ�ո�
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