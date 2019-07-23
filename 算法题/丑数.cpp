//编写一个程序判断给定的数是否为丑数。丑数就是只包含质因数2, 3, 5的正整数。
#include <stdio.h>
main()
{
	int n;
	printf("请输入需要判断的数字：");
	scanf("%d",&n); 
	if(n > 1)
	{
		while(n % 2 == 0)
			n /= 2;
		while(n % 3 == 0)
			n /= 3;
		while(n % 5 == 0)
			n /= 5;
		if(n == 1)
			printf("True");
		else
			printf("False");
	}
	else
		printf("False");
}
