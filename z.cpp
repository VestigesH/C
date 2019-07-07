#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

struct STU
{
	char name[20];
	char xuehao[20];
	int chinese;
	int math;
	int english;
	struct STU * next;
}stu;

/*******************************************************************以下为函数封装************************************************************************************/ 

//添加信息
void Add(struct STU * stu)
{
	system("cls");
	printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
	printf("\t\t\t  ┃                         添加学生信息                       ┃\n");
	printf("\t\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n"); 
	struct STU * NewStu = (struct STU *) malloc ( sizeof( struct STU ) );
	if(NewStu)
	{
	
		NewStu->next = stu->next;
		stu->next = NewStu;
		printf("\t\t\t请输入学生姓名：");
		scanf("%s",NewStu->name) ;
		printf("\t\t\t请输入学生学号：");
		scanf("%s",NewStu->xuehao);
		printf("\t\t\t请输入学生语文成绩：");
		scanf("%d",&NewStu->chinese);
		printf("\t\t\t请输入学生数学成绩：");
		scanf("%d",&NewStu->math);
		printf("\t\t\t请输入学生英语成绩：");
		scanf("%d",&NewStu->english);
		printf("\n\n\t\t\t\t\t\t      添加成功！");
	}
	else
		printf("\n\n\t\t\t\t\t\t      添加失败，请检查内存！"); 
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  按回车返回主菜单");
	getchar();
	getchar(); 
	
} 

//打印学生信息 
void PrintList(struct STU * stu)
{
	system("cls");
	printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
	printf("\t\t\t  ┃                         查看所有学生                        ┃\n");
	printf("\t\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n"); 
	struct STU * pMove = stu->next;
	if(pMove)
	{
		while(pMove)
			{
				printf("\t\t\t\t\t\t   姓名：%s\n",pMove->name);
				printf("\t\t\t\t\t\t   学号：%s\n",pMove->xuehao);
				printf("\t\t\t\t\t\t   语文：%d\n",pMove->chinese);
				printf("\t\t\t\t\t\t   数学：%d\n",pMove->math);
				printf("\t\t\t\t\t\t   英语：%d\n",pMove->english);
				printf("\n");
				pMove = pMove->next;
			}
			
	}
	else
	printf("\n\n\t\t\t\t\t\t   当前无学生信息！");
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  按回车返回主菜单");
	getchar();
	getchar();
}

//查找
void Search(struct STU * stu)
{
	system("cls");
	printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
	printf("\t\t\t  ┃                         查找学生信息                       ┃\n");
	printf("\t\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n"); 
	char name2[20];
	struct STU * pMove = stu->next;
	printf("\t\t\t\t\t\t 请输入学生姓名：");
	scanf("%s",name2);
	while(1)
	{
		if (pMove ==NULL)
		{
			printf("\n\n\n\n\t\t\t\t\t\t     查无此人！");
			break; 
		}
		if( strcmp( name2, pMove->name) != 0 )
			pMove = pMove->next;
		else if( strcmp( name2, pMove->name) == 0 )
		{
			printf("\n\n");
			printf("\t\t\t\t\t\t   姓名：%s\n",pMove->name);
			printf("\t\t\t\t\t\t   学号：%s\n",pMove->xuehao);
			printf("\t\t\t\t\t\t   语文：%d\n",pMove->chinese);
			printf("\t\t\t\t\t\t   数学：%d\n",pMove->math);
			printf("\t\t\t\t\t\t   英语：%d\n",pMove->english);
			break;
		}
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  按回车返回主菜单");
	getchar();
	getchar(); 
}

//删除
void Delete(struct STU * stu)
{
	system("cls");
	printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
	printf("\t\t\t  ┃                         删除学生信息                       ┃\n");
	printf("\t\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n"); 
	char name2[20];
	struct STU * pMove = stu->next;
	struct STU * pFront = stu;
	printf("\t\t\t\t\t\t 请输入学生姓名：");
	scanf("%s",name2);
	while(1)
	{
		if (pMove ==NULL)
		{
			printf("\n\n\n\n\t\t\t\t\t\t     查无此人！");
			break; 
		}
		if( strcmp( name2, pMove->name) != 0 )
		{
			pFront = pMove;
			pMove = pMove->next;
		}
		else if( strcmp( name2, pMove->name) == 0 )
		{
			pFront->next = pMove->next;
			free(pMove);
			printf("\n\n\n\n\t\t\t\t\t\t     删除成功！");
			break;
		}
	}
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  按回车返回主菜单");
	getchar();
	getchar(); 
} 

//修改信息
void Change(struct STU * stu)
{
	system("cls");
	printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
	printf("\t\t\t  ┃                         修改学生信息                       ┃\n");
	printf("\t\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n"); 
	char name2[20];
	int choice; 
	struct STU * pMove = stu->next;
	printf("\t\t\t\t\t\t 请输入学生姓名：");
	scanf("%s",name2);
	while(1)
	{
		if (pMove ==NULL)
		{
			printf("\n\n\n\n\t\t\t\t\t\t     查无此人！");
			break; 
		}
		if( strcmp( name2, pMove->name) != 0 )
			pMove = pMove->next;
		else if( strcmp( name2, pMove->name) == 0 )
		{
			printf("\n\n\n");
			printf("\t\t\t\t\t\t  ①姓名\n");
			printf("\t\t\t\t\t\t  ②学号\n");
			printf("\t\t\t\t\t\t  ③语文\n");
			printf("\t\t\t\t\t\t  ④数学\n");
			printf("\t\t\t\t\t\t  ⑤英语\n");
			
			printf("\n\n\n\t\t\t\t\t\t 请输入修改选项："); 
			scanf("%d",&choice);
			getchar();
			system("cls");
			printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
			printf("\t\t\t  ┃                         修改学生信息                       ┃\n");
			printf("\t\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n"); 
			printf("\n\n\n\t\t\t\t\t\t 将此项修改为："); 
			
			switch(choice)
			{
				case 1:
					scanf("%s",pMove->name);
					break;
				case 2:
					scanf("%s",pMove->xuehao);
					break;
				case 3:
					scanf("%d",pMove->chinese);
					break;
				case 4:
					scanf("%d",pMove->math);
					break;
				case 5:
					scanf("%d",pMove->english);
					break;
			}
			printf("\n\n\n\n\t\t\t\t\t\t     修改成功！");
			break;
		}
	}
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  按回车返回主菜单");
	getchar();
	getchar(); 
} 

//主界面
void Welcome(void)
{
	printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
	printf("\t\t\t  ┃* * * * * * * * * * * * 学生管理系统 * * * * * * * * * * * *┃\n");
	printf("\t\t\t  ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t\t  ┃                                                            ┃\n"); 
	printf("\t\t\t  ┃                      ① 添加学生信息                       ┃\n"); 
	printf("\t\t\t  ┃                                                            ┃\n"); 
	printf("\t\t\t  ┃                      ② 查找学生信息                       ┃\n"); 
	printf("\t\t\t  ┃                                                            ┃\n"); 
	printf("\t\t\t  ┃                      ③ 删除学生信息                       ┃\n"); 
	printf("\t\t\t  ┃                                                            ┃\n"); 
	printf("\t\t\t  ┃                      ④ 修改学生信息                       ┃\n"); 
	printf("\t\t\t  ┃                                                            ┃\n"); 
	printf("\t\t\t  ┃                      ⑤ 查看所有学生                       ┃\n"); 
	printf("\t\t\t  ┃                                                            ┃\n"); 
	printf("\t\t\t  ┃                      ⑥ 退出管理系统                       ┃\n"); 
	printf("\t\t\t  ┃                                                            ┃\n"); 
	printf("\t\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n"); 
	printf("\t\t\t\t\t\t   请选择功能:");
	 
	
}



/****************************************************************函数封装结束，以下为主函数***************************************************************************/
int main()
{
	struct STU * stu = (struct STU *) malloc ( sizeof( struct STU ) ); 
	stu->next = NULL;
	int choice;
	while(1)
	{
		system("cls");
		Welcome();
		scanf("%d",&choice);
		if (choice == 6)
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t感谢您的使用，程序将在2秒后关闭");
			Sleep(2000);
			system("cls");
			break; 
		}
		else
		{
			switch (choice)
			{
				case 1:
					Add(stu);
					break;
				case 2:
					Search(stu);
					break;
				case 3:
					Delete(stu);
					break;
				case 4:
					Change(stu);
					break;
				case 5:
					PrintList(stu);
					break;
			}
		}
	}
}
