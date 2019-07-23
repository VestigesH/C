#include <stdio.h>
#include <math.h>
int PrimeFactor(int m)
{
	int i;
	for(i = 2; i <= sqrt(m); i++)
    {
        while(m != i)     
        {
            if(m % i == 0)  
            {
                printf("%4d",i);
                m /= i;
            }
            else break;
        } 
    }
    printf("%4d",m);
    return m;
} 
int main()
{
	int m;
	printf("请输入一个整数:");
	scanf("%d",&m);
	PrimeFactor(m);
}
