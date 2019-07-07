#include <stdio.h>
#include <string.h>
int main()
{
	char A[40],B[40];
	printf("input:\n");
	gets(A);
	gets(B); 
	strcat(A,B);
	//strcpy(B,A);
	puts(A);
//	puts(B);
	return 0;
} 
