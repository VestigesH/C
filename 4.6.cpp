//����Ŀ���������ɴ��⣺ѧϰ�ɼ�>=90�ֵ�ͬѧ��A��ʾ��70~89��֮�����B��ʾ��60~79��֮����C��ʾ��60�����µ���D��ʾ�� 
#include <stdio.h>
int main(void)
{
	int score;
	printf("������ɼ���");
	scanf("%d",&score);
	if((score >= 90) ? printf("A") :(((score >= 70 && score <=89) ? printf("B") : (score >= 60 && score <= 69)? printf("C"):printf("D"))))
	return 0;
} 
