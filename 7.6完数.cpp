#include <stdio.h>
void Wanshu() 
{
	int i, n, sum;
	for(n = 1; n < 1000; n++)
	{
		sum = 0;
		for(i = 1; i < n; i++)
		{
			if(n % i == 0)
				sum += i;
		}
		if(n == sum)
			printf("%d ",n);
	}
}
int main()
{
	printf("1000内的完数有:");
	Wanshu();	
} 
