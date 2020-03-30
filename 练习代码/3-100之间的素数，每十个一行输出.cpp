#include <math.h>
#include <stdio.h>
main()
{
	int num, i, k, n;
	printf("3-100之间的素数为：\n");
	for(num = 3; num <= 100; num++)
	{
		k = sqrt(num);
		for(i = 2; i <= k; i++)
		{
			if(num % i == 0)
				break; 
		} 
		if( i >= k + 1)
		{
			printf("%d    ",num);
			n++;
			if( n % 10 == 0)
				printf("\n");
		}
	}
	
}
