#include <stdio.h>
int main()
{
	enum week{sun=7,mon=1,tue,wed,thu,fri,sta};
	enum week weekday;
	int i;
	printf("input integer:\n");
	scanf("%d",&i);
	weekday=(enum week)i;
	switch(weekday)
	{
		case sun:printf("Sunday\n");break;
		case mon:printf("Monday\n");break;
		case tue:printf("Tuesday\n");break;
		case wed:printf("Wednesday\n");break;
		case thu:printf("Thursday\n");break;
		case fri:printf("Friday\n");break;
		case sta:printf("Staurday\n");break;
		default:printf("Input error!\n");break;
	} 
} 
