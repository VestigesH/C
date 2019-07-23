#include <stdio.h>
#include <math.h>
void Daffodils()
{
	int n; 
	for(n = 100; n < 999; n++)
	{
		if(pow((n / 100), 3) + pow((n / 10 % 10), 3) + pow((n % 10), 3) == n )
			printf("%4d", n);
	}
}
int main()
{
	printf("100-999之间的水仙花数为：\n");
	Daffodils();
}
