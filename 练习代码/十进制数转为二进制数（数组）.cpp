#include <stdio.h>
main()
{
	int i = 0, n, d[40];
	scanf("%d",&n);
	while(n > 0)
	{
		d[i++] = n % 2;
		n = n / 2;
	}
	for(i--; i >= 0; i--)
		printf("%ld",d[i]);
	printf("\n");
} 
