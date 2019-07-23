//从键盘上输入一个大写字母，并将大写字母转化成小写字母并输出。
#include <stdio.h>
int main()
{
	char C,c;
	printf("请输入一个大写字母：");
	scanf("%c",&C);
	c=C+32;
	printf("%c",c);
	
}
