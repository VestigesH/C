//给定一个正整数 N，试求有多少组连续正整数满足所有数字之和为 N?
//思路：等差数列求和,首项小于等于所给数字N,公差为1 
#include <stdio.h>
#include <math.h>
int getNum(int N) 
{
	int start, end, i, n, num = 1;
	n = 2 * N; 
    for(i = 2; i <= sqrt(n); i++)
	{
        if(n % i == 0)
		{
            end = ( n / i + i - 1) / 2;
            start = end - n / i + 1;
            if((start + end) * (end - start + 1) == n)
                num++;
        }
    }
    return num;
}
main()
{
	int N, result;
	printf("请输入数字N:");
	scanf("%d",&N);
	result = getNum(N);
	printf("满足条件的组数为:%d",result);
}

