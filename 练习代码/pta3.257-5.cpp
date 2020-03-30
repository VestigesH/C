#include <stdio.h>
int main(int argc,const char *argv[])
{
	int n;
	scanf("%d",&n);
	int a[n];
	int b[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
		b[i] = 1;
	}
	for(int j = 0; j < n; j++)
	{
		if(b[j] == 1) 
		{
			for(int k = j + 1; k < n; k++)
			{
				if(a[j] == a[k]) 
				{
					b[j]++;
					b[k] = b[j];
				}
			} 
	    }
	}
	int cnt = b[0];
	int max = a[0];
	for(int kk=1;kk<n;kk++)
	{
		if(b[kk]>cnt)
		{
			cnt = b[kk];
			max = a[kk];
		}
	}
	printf("%d %d",max,cnt);
	return 0;
}
