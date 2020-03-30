#include <stdio.h>
main()
{
	int m, i, flag;
	printf("请输入一个正整数m:");
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
		printf("%d是素数",m);
	else
		printf("%d不是素数",m);
}
