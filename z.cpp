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

/*******************************************************************����Ϊ������װ************************************************************************************/ 

//�����Ϣ
void Add(struct STU * stu)
{
	system("cls");
	printf("\n\n\n\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t  ��                         ���ѧ����Ϣ                       ��\n");
	printf("\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n\n"); 
	struct STU * NewStu = (struct STU *) malloc ( sizeof( struct STU ) );
	if(NewStu)
	{
	
		NewStu->next = stu->next;
		stu->next = NewStu;
		printf("\t\t\t������ѧ��������");
		scanf("%s",NewStu->name) ;
		printf("\t\t\t������ѧ��ѧ�ţ�");
		scanf("%s",NewStu->xuehao);
		printf("\t\t\t������ѧ�����ĳɼ���");
		scanf("%d",&NewStu->chinese);
		printf("\t\t\t������ѧ����ѧ�ɼ���");
		scanf("%d",&NewStu->math);
		printf("\t\t\t������ѧ��Ӣ��ɼ���");
		scanf("%d",&NewStu->english);
		printf("\n\n\t\t\t\t\t\t      ��ӳɹ���");
	}
	else
		printf("\n\n\t\t\t\t\t\t      ���ʧ�ܣ������ڴ棡"); 
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  ���س��������˵�");
	getchar();
	getchar(); 
	
} 

//��ӡѧ����Ϣ 
void PrintList(struct STU * stu)
{
	system("cls");
	printf("\n\n\n\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t  ��                         �鿴����ѧ��                        ��\n");
	printf("\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n\n"); 
	struct STU * pMove = stu->next;
	if(pMove)
	{
		while(pMove)
			{
				printf("\t\t\t\t\t\t   ������%s\n",pMove->name);
				printf("\t\t\t\t\t\t   ѧ�ţ�%s\n",pMove->xuehao);
				printf("\t\t\t\t\t\t   ���ģ�%d\n",pMove->chinese);
				printf("\t\t\t\t\t\t   ��ѧ��%d\n",pMove->math);
				printf("\t\t\t\t\t\t   Ӣ�%d\n",pMove->english);
				printf("\n");
				pMove = pMove->next;
			}
			
	}
	else
	printf("\n\n\t\t\t\t\t\t   ��ǰ��ѧ����Ϣ��");
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  ���س��������˵�");
	getchar();
	getchar();
}

//����
void Search(struct STU * stu)
{
	system("cls");
	printf("\n\n\n\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t  ��                         ����ѧ����Ϣ                       ��\n");
	printf("\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n\n"); 
	char name2[20];
	struct STU * pMove = stu->next;
	printf("\t\t\t\t\t\t ������ѧ��������");
	scanf("%s",name2);
	while(1)
	{
		if (pMove ==NULL)
		{
			printf("\n\n\n\n\t\t\t\t\t\t     ���޴��ˣ�");
			break; 
		}
		if( strcmp( name2, pMove->name) != 0 )
			pMove = pMove->next;
		else if( strcmp( name2, pMove->name) == 0 )
		{
			printf("\n\n");
			printf("\t\t\t\t\t\t   ������%s\n",pMove->name);
			printf("\t\t\t\t\t\t   ѧ�ţ�%s\n",pMove->xuehao);
			printf("\t\t\t\t\t\t   ���ģ�%d\n",pMove->chinese);
			printf("\t\t\t\t\t\t   ��ѧ��%d\n",pMove->math);
			printf("\t\t\t\t\t\t   Ӣ�%d\n",pMove->english);
			break;
		}
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  ���س��������˵�");
	getchar();
	getchar(); 
}

//ɾ��
void Delete(struct STU * stu)
{
	system("cls");
	printf("\n\n\n\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t  ��                         ɾ��ѧ����Ϣ                       ��\n");
	printf("\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n\n"); 
	char name2[20];
	struct STU * pMove = stu->next;
	struct STU * pFront = stu;
	printf("\t\t\t\t\t\t ������ѧ��������");
	scanf("%s",name2);
	while(1)
	{
		if (pMove ==NULL)
		{
			printf("\n\n\n\n\t\t\t\t\t\t     ���޴��ˣ�");
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
			printf("\n\n\n\n\t\t\t\t\t\t     ɾ���ɹ���");
			break;
		}
	}
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  ���س��������˵�");
	getchar();
	getchar(); 
} 

//�޸���Ϣ
void Change(struct STU * stu)
{
	system("cls");
	printf("\n\n\n\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t  ��                         �޸�ѧ����Ϣ                       ��\n");
	printf("\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n\n"); 
	char name2[20];
	int choice; 
	struct STU * pMove = stu->next;
	printf("\t\t\t\t\t\t ������ѧ��������");
	scanf("%s",name2);
	while(1)
	{
		if (pMove ==NULL)
		{
			printf("\n\n\n\n\t\t\t\t\t\t     ���޴��ˣ�");
			break; 
		}
		if( strcmp( name2, pMove->name) != 0 )
			pMove = pMove->next;
		else if( strcmp( name2, pMove->name) == 0 )
		{
			printf("\n\n\n");
			printf("\t\t\t\t\t\t  ������\n");
			printf("\t\t\t\t\t\t  ��ѧ��\n");
			printf("\t\t\t\t\t\t  ������\n");
			printf("\t\t\t\t\t\t  ����ѧ\n");
			printf("\t\t\t\t\t\t  ��Ӣ��\n");
			
			printf("\n\n\n\t\t\t\t\t\t �������޸�ѡ�"); 
			scanf("%d",&choice);
			getchar();
			system("cls");
			printf("\n\n\n\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t  ��                         �޸�ѧ����Ϣ                       ��\n");
			printf("\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n\n"); 
			printf("\n\n\n\t\t\t\t\t\t �������޸�Ϊ��"); 
			
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
			printf("\n\n\n\n\t\t\t\t\t\t     �޸ĳɹ���");
			break;
		}
	}
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  ���س��������˵�");
	getchar();
	getchar(); 
} 

//������
void Welcome(void)
{
	printf("\n\n\n\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t  ��* * * * * * * * * * * * ѧ������ϵͳ * * * * * * * * * * * *��\n");
	printf("\t\t\t  �ǩ�������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t  ��                                                            ��\n"); 
	printf("\t\t\t  ��                      �� ���ѧ����Ϣ                       ��\n"); 
	printf("\t\t\t  ��                                                            ��\n"); 
	printf("\t\t\t  ��                      �� ����ѧ����Ϣ                       ��\n"); 
	printf("\t\t\t  ��                                                            ��\n"); 
	printf("\t\t\t  ��                      �� ɾ��ѧ����Ϣ                       ��\n"); 
	printf("\t\t\t  ��                                                            ��\n"); 
	printf("\t\t\t  ��                      �� �޸�ѧ����Ϣ                       ��\n"); 
	printf("\t\t\t  ��                                                            ��\n"); 
	printf("\t\t\t  ��                      �� �鿴����ѧ��                       ��\n"); 
	printf("\t\t\t  ��                                                            ��\n"); 
	printf("\t\t\t  ��                      �� �˳�����ϵͳ                       ��\n"); 
	printf("\t\t\t  ��                                                            ��\n"); 
	printf("\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n\n"); 
	printf("\t\t\t\t\t\t   ��ѡ����:");
	 
	
}



/****************************************************************������װ����������Ϊ������***************************************************************************/
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
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t��л����ʹ�ã�������2���ر�");
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
