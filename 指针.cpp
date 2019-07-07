#include <stdio.h>
int main()
{
	int a;
	char b;
	int *aint;
	char *ch;
	printf("请输入一个整数和一个字符:\n");
	scanf("%d,%c,",&a,&b);
	aint=&a;
	ch=&b;
	printf("直接输出整数:%d\n",a);
	printf("使用指针输出整数:%d\n",*aint);
	printf("直接输出字符: %c\n",b);
	printf("使用指针输出字符:%c\n",*ch);	
}
