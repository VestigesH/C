#include<stdio.h>
main()
{
	int a[10], b[10], i, j, n, count = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (j = 0; j < n - 1; j++)
	{
		b[j] = a[count + 1] - a[count];
		count++;
	}
	count = 0;
	for (j = 0; j < n - 1; j++)
	{
		if (j == 0)
			printf("%d", b[0]);
		else if (count == 3)
		{
			printf("\n");
			printf("%d",b[j]);
			count = 0;
		}
		else 
			printf(" %d", b[j]);	
		count++;
	}
}
