#include <stdio.h>
#include <math.h>
main()
{
	int m, i;
	i = 0;
	while(1)
	{
		scanf("%d",&m);
		if(m == 250)
			break;
		i++;
	}
	printf("%d",i+1);
	return 0;
}
