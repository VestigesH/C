#include<stdio.h>
main()
{
	int a[10], b[10], i, j, n, count=0;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
		scanf("%d",&a[i]);
	for(j = n - 1; j >= 0; j--)
	{
		b[count] = a[j];
		count++;
	}
	printf("%d",b[0]);
	for(i = 1; i < n; i++)
	{
		printf(" %d", b[i]);
	}
}
