#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
//定义函数 
 int tree(int n)
 {
 	int i,a,b,num;
 	int x=0;
 	srand((unsigned)time(NULL));
 	num=rand()%30+1;
//	第一层展示 
	for(i=1;i<=n;i++)
	{	
		x=6*n-2*i-8;
	 	num=rand()%x+1;
		printf("     ");

		for(a=1;a<num;a++)
			printf(" ");
			
		printf("*");
		
		for(a=num;a<x;a++)
			printf(" ");
			
		for(b=1;b<=4*i-3;b++)

				printf("*");
			
		for(a=1;a<num;a++)
			printf(" ");
			
		printf("*");
		printf("\n");
	}
	
	
//	第二层展示 
	for(i=n-1;i<=2*n-2;i++)
	{
		x=6*n-2*i-8;
	 	num=rand()%x+1;
		printf("     ");

		for(a=1;a<num;a++)
			printf(" ");
			
		printf("*");
		
		for(a=num;a<x;a++)
			printf(" ");
			
		for(b=1;b<=4*i-3;b++)
			printf("*");
			
		for(a=1;a<num;a++)
			printf(" ");
			
		printf("*");
		printf("\n");
	}
	
	
//	第三层展示 
	for(i=2*n-3;i<=3*n-4;i++)
	{
		x=6*n-2*i-8;
		if(i<3*n-4)
	 		num=rand()%x+1;
		printf("     ");

		if(i<3*n-4)
		{
			for(a=1;a<num;a++)
				printf(" ");
			printf("*");
		}
		
		for(a=num;a<x;a++)
			printf(" ");
			
		for(b=1;b<=4*i-3;b++)
			printf("*");
			
		if(i<3*n-4)
		{
			for(a=1;a<num;a++)
				printf(" ");
			printf("*");
		}
		printf("\n");
	}
	
	
//	树干展示 
	for(i=1;i<=n;i++)
	{
		x=5*n-10;
		num=rand()%x+1;
		printf("     ");
		
		for(a=1;a<num;a++)
			printf(" ");
			
		printf("*");
		
		for(a=num;a<x;a++)
			printf(" ");
		
		for(b=1;b<=2*n;b++)
			printf("|");

		num=rand()%20+1;
		
		for(a=1;a<num;a++)
			printf(" ");
			
		printf(" *");
		printf("\n");
	}
 }
 
 
//主函数部分 
int main()
{
	int n;
	printf("please enter the size of the Chirstmas tree you want:\n");
	scanf("%d",&n);
	while(1)
	{				
	system("color 02");
		tree(n);
		Sleep(3000);
		system("cls");
	}
	return 0;
} 

