#include <stdio.h>
insert(char s[])
{
	int i,j,t;
	for(i=1;i<=9;i++)
	{
		t=s[i];
		j=j-1;
		while((j>=0)&&(t<s[i]))
		{
			s[j+1]=s[j];
			j--;
		}
		s[j+1]=t;
	}
}
int main()
{
	char a[11];
	int i;
	printf("Input 10 character:");
	for(i=0;i<10;i++)
		a[i]=getchar();
	a[i]='\0';
	insert(a);
	printf("Sorted character is:%s\n",a);
}
