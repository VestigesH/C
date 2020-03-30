#include <stdio.h>
main()
{
	int sum, n, i, k;
	scanf("%d",&n);
	i = 1;
	k = -1;
	while(i <= n)
	{
		k = -k;
		sum += i * k;
		i++;
	}
	printf("%d",sum);
}
