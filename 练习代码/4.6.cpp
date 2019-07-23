//用三目运算符来完成此题：学习成绩>=90分的同学用A表示，70~89分之间的用B表示，60~79分之间用C表示，60分以下的用D表示。 
#include <stdio.h>
int main(void)
{
	int score;
	printf("请输入成绩：");
	scanf("%d",&score);
	if((score >= 90) ? printf("A") :(((score >= 70 && score <=89) ? printf("B") : (score >= 60 && score <= 69)? printf("C"):printf("D"))))
	return 0;
} 
