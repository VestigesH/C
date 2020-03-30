#include <stdio.h>
main()
{
	int n,i,a[1000]={0},sum=0,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j!=i)
				sum=sum+a[i]*10+a[j];
		}
	}
	printf("%d",sum);
	return 0;
}

