#include <stdio.h>
int evensum(int n)//��1-100֮��ż���ĺ� 
{
	int i,sum=0;
	for(i=2;i<n;i+=2)
		sum+=i;
	return sum;
}
int oddsum(int n)//��1-100֮�������ĺ�
{
	int i,sum=0;
	for(i=1;i<=n;i+=2)
		sum+=i;
	return sum; 
} 
int main()
{
	int n,sum,flag;
	int (*p)(int);
	printf("input n:");
	scanf("%d",&n);
	printf("input flag(0 or 1):");
	scanf("%d",&flag);
	if(flag==1) p=oddsum;
	else p=evensum;
	sum=(*p)(n);
	printf("sum=%d",sum);
}
