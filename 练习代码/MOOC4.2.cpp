#include <stdio.h>
main()
{
	int num;
	scanf("%d",&num);
	if(num <= 0)
	{
		printf("Data error!");
		return 0;
	}
	if(num % 5 == 0 && num % 7 == 0)
		printf("Yes!");
	else
		printf("No!");
	
}ok
