//返回所有长度为 N 且满足其每两个连续位上的数字之间的差的绝对值为 K 的非负整数。请注意，除了数字 0 本身之外，
//答案中的每个数字都不能有前导零。例如，01 因为有一个前导零，所以是无效的；但 0 是有效的。
//你可以按任何顺序返回答案。
#include <stdio.h>
void find(int num, int N, int K)
{
    if (N == 0) 
	{	
		printf("%d",num);
        return ;
    }
    int left = num % 10; 
    if (left + K <= 9)//取余后的数字比下一位小 
        find(num * 10 + left + K, N - 1, K);
    if (left - K >= 0)//取余后的数字比下一位大 
        find(num * 10 + left - K, N - 1, K);
}
void f(int N,int K)
{
	int i;
    for (i = 1; i <= 9; i++)//第一位以1开头 
        find(i, N - 1, K);      
}
main()
{
	int N, K;
	printf("请输入长度N和绝对值K：");
	scanf("%d %d",&N,&K);
	f(N, K);
 } 
