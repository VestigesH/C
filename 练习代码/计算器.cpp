#include <stdio.h>
#include <math.h>
#include <windows.h>
int main()
{
	double a,b,result;
	int choice;
	do
	{
		system("cls");
		printf("\n\n\n\t\t\t\t\t\t\t--------------------------------------------------\n\n");
		printf("\t\t\t\t\t\t\t|         ***** 您好,欢迎使用计算器 *****        |\n\n");
		printf("\t\t\t\t\t\t\t--------------------------------------------------\n\n");
		printf("\t\t\t\t\t\t\t|                1.加法运算                      |\n\n");
		printf("\t\t\t\t\t\t\t|                2.减法运算                      |\n\n");
		printf("\t\t\t\t\t\t\t|                3.乘法运算                      |\n\n");
		printf("\t\t\t\t\t\t\t|                4.除法运算                      |\n\n");
		printf("\t\t\t\t\t\t\t|                5.幂的运算                      |\n\n");
		printf("\t\t\t\t\t\t\t|                6.退出使用                      |\n\n"); 
		printf("\t\t\t\t\t\t\t--------------------------------------------------\n");
		printf("\n\n\t\t\t\t\t\t\t请在1-7之间进行选择您需要的功能:");
		scanf("%d",&choice);
		if(choice==6)  exit(0);
		switch(choice)
		{
			case 1:
				{
					system("cls");
					system("color 3f");
					printf("请输入两个需要进行加法运算的数：");
					scanf("%lf %lf",&a,&b);
					result = a + b;
					printf("计算结果为：%.2lf",result);
					Sleep(2000);
				}
				break;
			case 2:
				{
					system("cls");
					system("color 9f");
					printf("请输入被减数和减数：");
					scanf("%lf %lf",&a,&b);
					result = a - b;
					printf("计算结果为：%.2lf",result);
					Sleep(2000);
				}
				break;
			case 3:
				{
					system("cls");
					system("color Df");
					printf("请输入两个需要进行乘法运算的数：");
					scanf("%lf %lf",&a,&b);
					result = a * b;
					printf("计算结果为：%.2lf",result);
					Sleep(2000);
				}
				break;
			case 4:
				{
					system("cls");
					system("color Af");
					printf("请输入被除数和除数：");
					scanf("%lf %lf",&a,&b);
					result = a / b;
					printf("计算结果为：%.2lf",result);
					Sleep(2000);
				} 
				break;
			case 5:
				{
					system("cls");
					system("color Bf");
					printf("请输入底数和指数：");
					scanf("%lf %lf",&a,&b);
					result = pow(a,b);
					printf("计算结果为：%.2lf",result);
					Sleep(2000);
				} 
				break; 
			default :
					printf("请正确选择您所需的功能！");
					break;
		}
	}while(choice);
} 
