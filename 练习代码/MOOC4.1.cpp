#include <stdio.h>
main()
{
	int day;
	day = 2020 % 7;
	if(day == 1)
		printf("����һ");
	else if(day == 2)
		printf("���ڶ�");
	else if(day == 3)
		printf("������");
	else if(day == 4)
		printf("������");
	else if(day == 5)
		printf("������");
	else if(day == 6)
		printf("������");
	else
		printf("������"); 
}
