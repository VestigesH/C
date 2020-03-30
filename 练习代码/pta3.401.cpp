#include <stdio.h>
main()
{
	int n, sign;
	scanf("%d",&n);
	if(n < 0)
		sign = -1;
	else if(n == 0)
		sign = 0;
	else
		sign = 1;
	printf("sign(%d) = %d",n ,sign);
}
