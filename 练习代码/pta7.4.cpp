#include<stdio.h>
main()
{
	double sum;
	int m1, m2, m3, i;
	scanf("%lf",&sum);
	if (sum == 0 || sum == 1)
	{
		printf("1");
		return 0;
	} 
	else if(sum == 2)
	{
		printf("3");
		return 0;
	}
	m1 = 1;
	m2 = 1;
	for(i = 3; ; i++)
	{
		m3 = m1 + m2;
		if(m3 >= sum)
			break;
		m1 = m2;
		m2 = m3;
	}
	printf("%d",i); 
}

