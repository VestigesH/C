#include <stdio.h>
main()
{
	int m, i, flag;
	printf("������һ��������m:");
	scanf("%d",&m);
	flag = 1;
	for(i = 2; i < m; i++)
	{
		if( m % i == 0) 
		{
			flag = 0;
			i = m;
		}
	} 
	if(flag == 1)
		printf("%d������",m);
	else
		printf("%d��������",m);
}
