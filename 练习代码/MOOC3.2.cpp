#include <stdio.h>
main()
{
	int num, a, b, c, num1;
	scanf("%d",&num);
	c = num / 100;
	b = (num / 10) % 10;
	a = num % 10;
	num1 = a * 1 + b * 8 + c * 64;
	printf("%d(8)=%d(10)",num,num1);
}
