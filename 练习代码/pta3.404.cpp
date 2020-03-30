#include <stdio.h>
main()
{
	int v, lv;
	double exceed; 
	scanf("%d %d",&v, &lv);
	exceed =(double)(v - lv) / lv * 100.0;
	if(exceed < 10)
	{
		printf("OK");
	}
	else if(exceed >= 10 && exceed < 50)
	{
		printf("Exceed %.0lf%%. Ticket 200",exceed);
	}
	else 
	{
		printf("Exceed %.0lf%%. License Revoked",exceed);
	}

		
}
