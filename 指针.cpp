#include <stdio.h>
int main()
{
	int a;
	char b;
	int *aint;
	char *ch;
	printf("������һ��������һ���ַ�:\n");
	scanf("%d,%c,",&a,&b);
	aint=&a;
	ch=&b;
	printf("ֱ���������:%d\n",a);
	printf("ʹ��ָ���������:%d\n",*aint);
	printf("ֱ������ַ�: %c\n",b);
	printf("ʹ��ָ������ַ�:%c\n",*ch);	
}
