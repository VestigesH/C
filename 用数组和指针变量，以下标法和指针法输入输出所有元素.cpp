#include <stdio.h>
int main()
{
	int i=0;
	int array[6];
	int *p=array;
	printf("\n please input array [6]: \n");
	while(p<(array+6)) scanf("%d",p++);
	printf("\n Output array [i]: \n");
	for(i=0;i<6;i++) printf("%d",array[i]);     //1.数组名，下标法 
	printf("\n Output *(array+i):\n ");
	for(i=0;i<6;i++) printf("%d, ",*(array+i)); //2.数组名，指针法
	printf("\n Output p[i]: \n");
	p=array;                                    //p指向数组的首地址  
	for(i=0;i<6;i++) printf("%d, ",p[i]);       //3.指针变量,下标法 
	printf("\n Output *(p+i): \n");				
	for(i=0;i<6;i++) printf("%d, ",*(p+i));		//4.指针变量,指针法
	printf("\n Output *p++:\n");
	while(p<(array+6)) printf("%d, ",*p++);     //5.指针变量,指针法,效率最高 
	printf("\n");
}
