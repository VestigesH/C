#include <stdio.h>
#include <stdlib.h>
int main()
{
	char d[20];int i ;
	printf("please input 10 char:\n");
	for(i=0;i<10;i++)
	scanf("%",&d[i]);
	d[i]='\0';
	for(i=0;i<10;i++)
	printf("%c",d[i]);
	printf("\n");
	printf("%s",d);
}
