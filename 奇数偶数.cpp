#include <stdio.h>
int main()
{
	int number;
	printf("\n������һ������:");
	scanf("%d",&number);
	if (number%2==0)
		printf("\n����%d��һ��ż����",number);
	else
		printf("\n����%d��һ��������",number);		 
}
