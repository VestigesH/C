#include <stdio.h>
#include <ctype.h>
int main()
{
	int a;
	char b;
	int *aint=&a;
	char *ch=&b;
	printf("������һ��������һ���ַ�:\n");
	scanf("%d,%c",&a,&b);
	*aint=*aint+24;
	*ch=tolower(*ch);
	printf("�ı�������:%d\n",*aint);
	printf("�ı����ַ�:%c\n",*ch);
}
