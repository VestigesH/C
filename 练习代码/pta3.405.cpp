#include <stdio.h>
main()
{
	int a, b;
	char c;
	double price;
	scanf("%d %d %c",&a ,&b ,&c);
	if(b == 90)
	{
		price = a * 6.95;
	}
	else if(b == 93)
	{
		price = a * 7.44;
	}
	else if(b == 97)
	{
		price = a * 7.93;
	}
	else 
		return 0;
	if(c == 'm')
	{
		price *= 0.95;
	}
	else if(c == 'e')
	{
		price *= 0.97;
	}
	printf("%.2lf",price);
}
