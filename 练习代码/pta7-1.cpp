#include <stdio.h>
main()
{
	int i, m, sum, sum1;
	sum = 0;
	sum1 = 1;
	scanf("%d",&m);
	if(m <= 12)
	{
		for(i = 1; i <= m; i++)
		{
			sum1 = sum1 * i;
			sum += sum1; 
		}
		printf("%d",sum);
	}
	else
		return 0;
}
