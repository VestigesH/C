#include <stdio.h>
int main(void)
{
	float x;
	float sum=0;
	scanf("%f",&x);
	while(x>0)
	{
		sum+=x;
		scanf("%f",&x);
	}
	printf("��=%6.2f",sum);
}
