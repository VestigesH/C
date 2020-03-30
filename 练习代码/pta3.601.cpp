#include <stdio.h>
main()
{
	int year, month, days, sum = 0, Feb;
	scanf("%d/%d/%d", &year, &month, &days);
	if((year % 4 == 0 && year %100 != 0) || year % 400 == 0)
		Feb = 29;
	else
		Feb = 28;
	switch (month)
	{
		case 1:
			sum += days;
			break;
		case 2:
			sum += 31 + days;
			break; 
		case 3:
			sum += 31 + Feb + days; 
			break;
		case 4:
			sum += 31 + Feb + 31 + days;
			break;
		case 5:
			sum += 31 + Feb + 31 + 30 + days;
			break;
		case 6:
			sum += 31 + Feb + 31 + 30 + 31 + days;
			break;
		case 7:
			sum += 31 + Feb + 31 + 30 + 31 + 30 + days;
			break;
		case 8:
			sum += 31 + Feb + 31 + 30 + 31 + 30 + 31 + days;
			break;
		case 9: 
			sum += 31 + Feb + 31 + 30 + 31 + 30 + 31 + 31 + days;
			break;
		case 10:
			sum += 31 + Feb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + days;
			break;
		case 11:
			sum += 31 + Feb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + days;
			break;
		case 12:
			sum += 31 + Feb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + days;
			break;
	}
	printf("%d",sum);
 }
