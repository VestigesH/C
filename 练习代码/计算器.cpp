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
		printf("\t\t\t\t\t\t\t|         ***** ����,��ӭʹ�ü����� *****        |\n\n");
		printf("\t\t\t\t\t\t\t--------------------------------------------------\n\n");
		printf("\t\t\t\t\t\t\t|                1.�ӷ�����                      |\n\n");
		printf("\t\t\t\t\t\t\t|                2.��������                      |\n\n");
		printf("\t\t\t\t\t\t\t|                3.�˷�����                      |\n\n");
		printf("\t\t\t\t\t\t\t|                4.��������                      |\n\n");
		printf("\t\t\t\t\t\t\t|                5.�ݵ�����                      |\n\n");
		printf("\t\t\t\t\t\t\t|                6.�˳�ʹ��                      |\n\n"); 
		printf("\t\t\t\t\t\t\t--------------------------------------------------\n");
		printf("\n\n\t\t\t\t\t\t\t����1-7֮�����ѡ������Ҫ�Ĺ���:");
		scanf("%d",&choice);
		if(choice==6)  exit(0);
		switch(choice)
		{
			case 1:
				{
					system("cls");
					system("color 3f");
					printf("������������Ҫ���мӷ����������");
					scanf("%lf %lf",&a,&b);
					result = a + b;
					printf("������Ϊ��%.2lf",result);
					Sleep(2000);
				}
				break;
			case 2:
				{
					system("cls");
					system("color 9f");
					printf("�����뱻�����ͼ�����");
					scanf("%lf %lf",&a,&b);
					result = a - b;
					printf("������Ϊ��%.2lf",result);
					Sleep(2000);
				}
				break;
			case 3:
				{
					system("cls");
					system("color Df");
					printf("������������Ҫ���г˷����������");
					scanf("%lf %lf",&a,&b);
					result = a * b;
					printf("������Ϊ��%.2lf",result);
					Sleep(2000);
				}
				break;
			case 4:
				{
					system("cls");
					system("color Af");
					printf("�����뱻�����ͳ�����");
					scanf("%lf %lf",&a,&b);
					result = a / b;
					printf("������Ϊ��%.2lf",result);
					Sleep(2000);
				} 
				break;
			case 5:
				{
					system("cls");
					system("color Bf");
					printf("�����������ָ����");
					scanf("%lf %lf",&a,&b);
					result = pow(a,b);
					printf("������Ϊ��%.2lf",result);
					Sleep(2000);
				} 
				break; 
			default :
					printf("����ȷѡ��������Ĺ��ܣ�");
					break;
		}
	}while(choice);
} 
