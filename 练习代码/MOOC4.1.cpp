#include <stdio.h>
main()
{
	int day;
	day = 2020 % 7;
	if(day == 1)
		printf("星期一");
	else if(day == 2)
		printf("星期二");
	else if(day == 3)
		printf("星期三");
	else if(day == 4)
		printf("星期四");
	else if(day == 5)
		printf("星期五");
	else if(day == 6)
		printf("星期六");
	else
		printf("星期日"); 
}
