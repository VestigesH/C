#include <stdio.h>
#include <math.h>
main()
{
	int a, n, s, i, s1;
	s = 0;
	s1 = 0;
	scanf("%d %d",&a, &n);
	for(i = 1; i <= n; i++)
	{
		
		s1 += a * (pow(10, i-1));
		s += s1;
		
	}
	printf("s = %d",s);
} 
