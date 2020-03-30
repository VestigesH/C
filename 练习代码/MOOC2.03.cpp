#include <stdio.h>
main()
{
	int num, g, s, b;
	scanf("%d",&num);
	b = num / 100;
	g = num % 10;
	s = (num - (b * 100)) / 10;
	printf("%d%d%d",g,s,b);
}
