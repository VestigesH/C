#include <stdio.h>
#include <ctype.h>
int main()
{
	int a;
	char b;
	int *aint=&a;
	char *ch=&b;
	printf("请输入一个整数和一个字符:\n");
	scanf("%d,%c",&a,&b);
	*aint=*aint+24;
	*ch=tolower(*ch);
	printf("改变后的整数:%d\n",*aint);
	printf("改变后的字符:%c\n",*ch);
}
