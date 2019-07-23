#include <stdio.h>
#include <string.h> 
int main()
{
	char a[201],b[201];
	int i,j,k,m,n;
	scanf("%s",a);
	scanf("%s",b);
	m=strlen(a);
	k=n=strlen(b);
	if(m>k) k=m;
	a[k+1]=0;
	for(i=0;i<k;i++) a[k-i]=a[m-i-1];
	for(i=0;i<k-1;i++) a[i]='0';
	for(i=0;i<k;i++) b[k-i]=b[n-i-1];
	for(i=0;i<=k-n;i++) b[i]='0';
	j=0;
	for(i=0;i<k;i++)
	{
		j=(a[k-1]+b[k-1]+j-96);
		a[k-i]=j%10+48;
		j=j/10;
	}
	if(a[0]=='\0') printf("%s\n",a+1);
	else printf("%s\n",a);
}
