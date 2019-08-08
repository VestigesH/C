//统计所有小于非负整数 n 的质数的数量。
#include <stdio.h>
main()
{
	int n, i, j, counter = 0;
	printf("请输入非负整数n：");
	scanf("%d",&n);
	for(i = 2; i < n; i++)
	{
		for(j = 2; j < i; j++)
		{
			if(i % j == 0)	break;	
		}
		if(i==j) counter++;
	}
	printf("%d",counter);
}

