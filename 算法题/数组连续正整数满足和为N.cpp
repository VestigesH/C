//����һ�������� N�������ж���������������������������֮��Ϊ N?
//˼·���Ȳ��������,����С�ڵ�����������N,����Ϊ1 
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
	printf("����������N:");
	scanf("%d",&N);
	result = getNum(N);
	printf("��������������Ϊ:%d",result);
}

