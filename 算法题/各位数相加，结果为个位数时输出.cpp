//����һ���Ǹ����� num,����������λ�ϵ�������ӣ�ֱ�����Ϊһλ����
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
	printf("������Ǹ�����num��");
	scanf("%d", &num);
	result = GetNumber(num);
	printf("\n������Ϊ��%d",result);
}
