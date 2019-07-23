#include<stdio.h>
int main()
{
	int a[2][2]={2,0,4,8};
	
	scanf ("%d",&**(a+1));
	printf("%d",**(a+1));
	
	return 0;
}
