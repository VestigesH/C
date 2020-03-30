#include <stdio.h>
main()
{
	int N;
	scanf("%d",&N);
	if(N <= 1000 && N > 0)
	{
		if((N % 5) >= 1 && (N % 5) <= 3)
		{
			printf("Fishing in day%d",N);
		}
		else
		{
			printf("Drying in day%d",N);
		}
			
	}
	else
		return 0;
}
