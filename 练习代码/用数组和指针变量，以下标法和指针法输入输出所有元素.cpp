#include <stdio.h>
int main()
{
	int i=0;
	int array[6];
	int *p=array;
	printf("\n please input array [6]: \n");
	while(p<(array+6)) scanf("%d",p++);
	printf("\n Output array [i]: \n");
	for(i=0;i<6;i++) printf("%d",array[i]);     //1.���������±귨 
	printf("\n Output *(array+i):\n ");
	for(i=0;i<6;i++) printf("%d, ",*(array+i)); //2.��������ָ�뷨
	printf("\n Output p[i]: \n");
	p=array;                                    //pָ��������׵�ַ  
	for(i=0;i<6;i++) printf("%d, ",p[i]);       //3.ָ�����,�±귨 
	printf("\n Output *(p+i): \n");				
	for(i=0;i<6;i++) printf("%d, ",*(p+i));		//4.ָ�����,ָ�뷨
	printf("\n Output *p++:\n");
	while(p<(array+6)) printf("%d, ",*p++);     //5.ָ�����,ָ�뷨,Ч����� 
	printf("\n");
}
