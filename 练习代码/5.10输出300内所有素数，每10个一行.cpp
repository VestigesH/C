//��дһ���������300�����е�������ÿ10��һ��
#include <stdio.h>
int main()
{
	int counter=0;
	int n,i;
	for(n=2;n<300;n++)
	{
		for(i=2;i<n;i++)
		{
			if (n%i==0)
			break;
		}
		if (i>=n)
		{
			counter=counter+1;
			printf("%5d",n);
			if(counter%10==0)
			{
				printf("\n");
			}
		}	
	}
}
