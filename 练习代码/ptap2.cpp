#include <stdio.h>
main()
{
	int num, g, s, b;
	scanf("%d",&num);
	g = num % 10;
	b = num / 100;
	s = (num / 10) % 10;
	if(g == 0 && s == 0)
		printf("%d",b);
	else if( g == 0)
		printf("%d%d",s,b);
	else
		printf("%d%d%d",g,s,b);
}
