//�������г���Ϊ N ��������ÿ��������λ�ϵ�����֮��Ĳ�ľ���ֵΪ K �ķǸ���������ע�⣬�������� 0 ����֮�⣬
//���е�ÿ�����ֶ�������ǰ���㡣���磬01 ��Ϊ��һ��ǰ���㣬��������Ч�ģ��� 0 ����Ч�ġ�
//����԰��κ�˳�򷵻ش𰸡�
#include <stdio.h>
void find(int num, int N, int K)
{
    if (N == 0) 
	{	
		printf("%d",num);
        return ;
    }
    int left = num % 10; 
    if (left + K <= 9)//ȡ�������ֱ���һλС 
        find(num * 10 + left + K, N - 1, K);
    if (left - K >= 0)//ȡ�������ֱ���һλ�� 
        find(num * 10 + left - K, N - 1, K);
}
void f(int N,int K)
{
	int i;
    for (i = 1; i <= 9; i++)//��һλ��1��ͷ 
        find(i, N - 1, K);      
}
main()
{
	int N, K;
	printf("�����볤��N�;���ֵK��");
	scanf("%d %d",&N,&K);
	f(N, K);
 } 
