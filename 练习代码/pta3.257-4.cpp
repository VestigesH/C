#include<stdio.h>
#define N 4
int main()
{
	int i = 3, x;
	int a[N];
	int temp;
	scanf("%d", &x);
	while (i != -1) 
	{
		a[i] = x % 10;
		x = x / 10;
		i--;
	}
	for (i = 0; i < N; i++)
		a[i] = a[i] + 9;
	for (i = 0; i < N; i++)
		a[i] = a[i] % 10;
	for (i = 0; i < 2; i++)
	{
		temp = a[i];
		a[i] = a[i + 2];
		a[i + 2] = temp;
	}
	printf("The encrypted number is ");
	for (i = 0; i < N; i++)
	{
		printf("%d", a[i]);
	}
	return 0;
}
