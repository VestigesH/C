#include <stdio.h>
int main()
{
	int b[3][5]={{31,32,33,24,25},{16,17,8,9,10},{19,11,51,14,15}};
	int *q;
	int (*p)[5];
	for(p=b;p<b+3;p++)
	{
		for(q=*p;q<*p+5;q++)
			printf("%5d",*q);
		printf("\n");
	}
}
