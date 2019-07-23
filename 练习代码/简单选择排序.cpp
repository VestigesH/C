#include <stdio.h>
int main()
{
	int i,j,k,n;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(a[k]>a[j])
				k=j;
		}
		if(k!=i)
		{
			t=a[i];	
			a[i]=a[k];
			a[k]=t;
		}
	}
} 
