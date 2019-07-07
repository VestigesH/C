//给定一个非负整数 num,反复将各个位上的数字相加，直到结果为一位数。
#include  <stdio.h>
int GetNumber(int n)
{
	int result, t;
	while(n > 0)
	{
		t =  n % 10;
		n /= 10;
		result += t;
		printf("%d \t",t);
	}
	if(result > 0 && result <10)
		return result;
	else
		GetNumber(result); 
}
main()
{
	int num, result;
	printf("请输入非负整数num：");
	scanf("%d", &num);
	result = GetNumber(num);
	printf("\n运算结果为：%d",result);
}
