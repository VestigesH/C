#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define N 50 

struct med 
{
	int  num;        //���� 
	char name[N];    //ҩ��
	char gx[N];      //��Ч 
	int  xl;         //����  
	char type[N];    //��� 
	char scrq[N];    //��������
	char bzq[N];     //������ 
	float price;     //���� 
	int  kc;         //��� 
	struct med *next;  //ָ���� 
};               //ҩƷ��Ϣ�ṹ�� 
int count;           //��¼ҩƷ����
int icount; 

struct med *readfile();
void menu()     //�˵����� 
{
	printf("\n\t\t\t\t�������������");
	getch();
	system("cls"); 
	printf("\n");
	printf("\n\t\t\t************ҩ�����ϵͳ����ǰ��%2d��ҩ����Ϣ************\n",count);
	printf("\t\t\t*                1.¼��ҩƷ��Ϣ                        *\n");
	printf("\t\t\t*                2.��ʾ������Ϣ                        *\n");
	printf("\t\t\t*                3.���ҩƷ��Ϣ                        *\n");
	printf("\t\t\t*                4.����ҩƷ��Ϣ                        *\n");
	printf("\t\t\t*                5.ɾ��ҩƷ��Ϣ                        *\n"); 
	printf("\t\t\t*                6.�޸�ҩƷ��Ϣ                        *\n"); 
	printf("\t\t\t*                7.ҩƷ��Ϣ����                        *\n"); 
	printf("\t\t\t*                8.ͳ��ҩƷ��Ϣ                        *\n");
	printf("\t\t\t*                9.�޸Ĺ�������                        *\n");
	printf("\t\t\t*                0.   ��   ��                          *\n");
	printf("\t\t\t********************************************************\n");
	printf("\t\t\t\t\t��ѡ��һ�����ܣ�0-9����"); 
}
void writefile(struct med *pHead);    //д���ļ����� 
struct med *GWC(struct med *pHead,struct med *L);
void YH();
struct med *Create()  //������Ϣ���������ļ� 
{
	struct med *pHead;
	struct med *p,*pNew;
	count=0;
	pHead=(struct med *)malloc(sizeof(struct med)); //Ϊͷ�ڵ������ڴ�ռ� 
	pHead->next=pHead;          //����һ�������� 
	p=pHead;
	printf("\n����������ҩƷ��Ϣ���Ա��0��������\n");
	while(1)
	{
		count++;
		printf("\n�������%d��ҩƷ����Ϣ��\n",count);	
		pNew=(struct med *)malloc(sizeof(struct med));
		printf("��ţ�");
		scanf("%d",&pNew->num);
		if(pNew->num==0) break;
		printf("ҩ����"); 
		scanf("%s",pNew->name);
		printf("��Ч��");
		scanf("%s",pNew->gx);
		printf("������"); 
		scanf("%d",&pNew->xl);
		printf("���"); 
		scanf("%s",pNew->type);
		printf("��������(��:2017-5-1)��");
		scanf("%s",pNew->scrq);
		printf("�����ڣ�");
		scanf("%s",pNew->bzq);
		printf("���ۣ�");
		scanf("%f",&pNew->price);
		printf("��棺");
		scanf("%d",&pNew->kc);
		pNew->next=NULL;
		p->next=pNew;
		p=pNew;
		system("cls");	
	}             //���������� 
	count=count-1;     //ͳ���������� 
	free(pNew);     //�ͷŽڵ� 
	writefile(pHead);
	printf("��Ϣ������ɣ�\n"); 
	return pHead;
}
void print(struct med *pHead)  //�����Ϣ 
{ 
	struct med *t;
	t=pHead->next;
	if(t==NULL)
	{
		printf("\n��ǰû��ҩƷ��Ϣ��\n");
		printf("�Ƿ�¼����Ϣ(Y/N)?\n");
		if(toupper(getche())=='Y')  Create();
	}
	else
	{
		printf("\n----------------------------------------------------------------------------------------------------\n");
		printf("|                          ****ҩƷ����ϵͳ����ǰ��%2d��ҩƷ��Ϣ****                                |\n",count);
		printf("----------------------------------------------------------------------------------------------------\n"); 
		printf("|  ���  |       ҩ��       |       ��Ч       | ���� |  ���  |  ��������  | ������ | ���� | ��� |\n");
		while(t)
		{
			printf("----------------------------------------------------------------------------------------------------\n");  
			printf("|%7d ",t->num);
			printf("|%17s ",t->name);
			printf("|%18s",t->gx);
			printf("|%6d",t->xl);
			printf("|%8s",t->type);
			printf("|%11s ",t->scrq);
			printf("|%7s ",t->bzq);
			printf("|%5.1f ",t->price);
			printf("|%5d |",t->kc);
			printf("\n");
			t=t->next;
	  	}
	  	printf("----------------------------------------------------------------------------------------------------\n");  
	} 
}
void writefile(struct med *pHead)  //д���ļ� 
{
	struct med *t;
    FILE *fp;
	fp=fopen("d:\\medfile.txt","w");
	t=pHead->next;
	while(t)
	{
		fprintf(fp,"%d %s %s %d %s %s %s %f %d\n",t->num,t->name,t->gx,t->xl,t->type,t->scrq,t->bzq,t->price,t->kc);
		t=t->next;
	}
	fclose(fp);
	printf("\n\t\t\t\tд���ļ��ɹ���\n");
}
struct med *readfile()     //��ȡ�ļ���Ϣ 
{
	struct med *pHead;
	struct med *p,*pNew;
	FILE *fp;
	count=0;
	fp=fopen("d:\\medfile.txt","r");
	if(fp==NULL)
	{
		printf("\n\t\t\t\t�ļ���ʧ�ܣ�\n");
		getch();
		exit(1);
	}
	pHead=(struct med *)malloc(sizeof(struct med));
	pHead->next=pHead;
	p=pHead;
	while(!feof(fp))
	{
		pNew=(struct med *)malloc(sizeof(struct med));
		fscanf(fp,"%d %s %s %d %s %s %s %f %d\n",&pNew->num,pNew->name,pNew->gx,&pNew->xl,pNew->type,pNew->scrq,pNew->bzq,&pNew->price,&pNew->kc);
		p->next=pNew;
		p=pNew;	
	    count++;
	}
	p->next=NULL;
	fclose(fp);
	printf("\n\t\t\t\t��ȡ�ļ��ɹ���\n");
	return pHead;	
}


void YMCX(struct med *pHead)      //��ҩ����ѯ��Ϣ 
{
	int m=1,n=1;
	int flag=1;
	struct med *t;
	char name[N];
	system("cls");
	printf("\n\t\t\t\t����������ҵ�ҩ����"); 
	scanf("%s",name);
	t=pHead->next;
	while(t)
	{
		if(strcmp(name,t->name)==0)
		{
			if(n==1)
			{
				printf("----------------------------------------------------------------------------------------------------\n");
				printf("|  ���  |       ҩ��       |       ��Ч       | ���� |  ���  |  ��������  | ������ | ���� | ��� |\n");
				printf("----------------------------------------------------------------------------------------------------\n");
				n=0; 
			}
			printf("|%7d ",t->num);
			printf("|%17s ",t->name);
			printf("|%18s",t->gx);
			printf("|%6d",t->xl);
			printf("|%8s",t->type);
			printf("|%11s ",t->scrq);
			printf("|%7s ",t->bzq);
			printf("|%5.1f ",t->price);
			printf("|%5d |",t->kc);
			printf("\n");
		  	printf("----------------------------------------------------------------------------------------------------\n");
		  	m=0;
		}
		t=t->next;
	} 
	if(t==NULL&&m==1) printf("\n\t\t\t\tδ�ҵ�����ҵ�ҩƷ��\n"); 
}
void BHCX(struct med *pHead)      //����Ų�ѯ��Ϣ 
{
	int k,m=1,n=1;
	int flag=1;
	int num;
	struct med *t;
	system("cls");
	printf("\n\t\t\t\t����������ҵı�ţ�"); 
	scanf("%d",&num);
	t=pHead->next;
	while(t)
	{
		if(t->num==num)
		{
			if(n==1)
			{
				printf("----------------------------------------------------------------------------------------------------\n");
				printf("|  ���  |       ҩ��       |       ��Ч       | ���� |  ���  |  ��������  | ������ | ���� | ��� |\n");
				printf("----------------------------------------------------------------------------------------------------\n");
				n=0; 
			}
			printf("|%7d ",t->num);
			printf("|%17s ",t->name);
			printf("|%18s",t->gx);
			printf("|%6d",t->xl);
			printf("|%8s",t->type);
			printf("|%11s ",t->scrq);
			printf("|%7s ",t->bzq);
			printf("|%5.1f ",t->price);
			printf("|%5d |",t->kc);
			printf("\n");
		  	printf("----------------------------------------------------------------------------------------------------\n");
		  	m=0;
		  	break;
		}
		t=t->next;
	} 
	if(t==NULL&&m==1) printf("\n\t\t\t\tδ�ҵ�����ҵ�ҩƷ��\n");
}
void GXCX(struct med *pHead)      //����Ч��ѯ��Ϣ 
{
	int m=1,n=1;
	int flag=1;
	struct med *t;
	char gx[N];
	system("cls");
	printf("\n\t\t\t\t����������ҵĹ�Ч��"); 
	scanf("%s",gx);
	t=pHead->next;
	while(t)
	{
		if(strcmp(gx,t->gx)==0)
		{
			if(n==1)
			{
				printf("----------------------------------------------------------------------------------------------------\n");
				printf("|  ���  |       ҩ��       |       ��Ч       | ���� |  ���  |  ��������  | ������ | ���� | ��� |\n");
				printf("----------------------------------------------------------------------------------------------------\n");
				n=0; 
			}
			printf("|%7d ",t->num);
			printf("|%17s ",t->name);
			printf("|%18s",t->gx);
			printf("|%6d",t->xl);
			printf("|%8s",t->type);
			printf("|%11s ",t->scrq);
			printf("|%7s ",t->bzq);
			printf("|%5.1f ",t->price);
			printf("|%5d |",t->kc);
			printf("\n");
		  	printf("----------------------------------------------------------------------------------------------------\n");
			m=0;
		}
		t=t->next;
	} 
	if(t==NULL&&m==1) printf("\n\t\t\t\tδ�ҵ�����ҵ�ҩƷ��\n");
}
void KCCX(struct med *pHead)
{
	int k=1,n=1;
	int flag=1;
	struct med *t;
	int kc;
	system("cls");
	printf("\n\t\t\t\t����������ҵ�ҩƷ��棺"); 
	scanf("%d",&kc);
	t=pHead->next;
	while(t)
	{
		if(t->kc>=kc)
		{
			if(n==1)
			{
				printf("----------------------------------------------------------------------------------------------------\n");
				printf("|  ���  |       ҩ��       |       ��Ч       | ���� |  ���  |  ��������  | ������ | ���� | ��� |\n");
				printf("----------------------------------------------------------------------------------------------------\n");
				n=0; 
			}
			printf("|%7d ",t->num);
			printf("|%17s ",t->name);
			printf("|%18s",t->gx);
			printf("|%6d",t->xl);
			printf("|%8s",t->type);
			printf("|%11s ",t->scrq);
			printf("|%7s ",t->bzq);
			printf("|%5.1f ",t->price);
			printf("|%5d |",t->kc);
			printf("\n");
		  	printf("----------------------------------------------------------------------------------------------------\n");
			k=0; 
		}
		t=t->next;
	} 
	if(t==NULL&&k==1) printf("\n\t\t\t\tδ�ҵ�����ҵ�ҩƷ��\n");
}
void CX(struct med *pHead)
{
	int c,flag=1;
	do
	{
		system("cls");
		printf("\t\t\t��ѡ�����ѯ�ķ�ʽ��\n");
		printf("\t\t\t----------------------------------------\n"); 
		printf("\t\t\t|1.ҩ��|   |2.���|   |3.��Ч|   |4.���|\n");
		printf("\t\t\t----------------------------------------\n");
		printf("\t\t\t�����룺");
		scanf("%d",&c);
		switch(c)
		{
			case 1:YMCX(pHead); break;
			case 2:BHCX(pHead); break;
			case 3:GXCX(pHead); break; 
			case 4:KCCX(pHead); break;
			default:printf("\t\t\t\t��������\n"); break;
		}
		printf("\n\t\t\t\t�Ƿ�������ң�Y/N����");
		if(toupper(getche())=='Y') flag=1;
		else flag=0;
	}while(flag);
}

struct med *TJ(struct med *pHead)     //�����Ϣ 
{
	struct med *s,*t,*p;
	int k,m,flag;
	FILE *fp;
	do
	{
		k=m=0; 
		s=(struct med *)malloc(sizeof(struct med));
		printf("\n\t\t\t\t����������ӵ�ҩƷ��Ϣ��\n"); 
		printf("\t\t\t\tҩ����");
		scanf("%s",s->name);
		t=pHead->next; 
		while(t)
		{
			if(strcmp(s->name,t->name)==0)
			{
				printf("\t\t\t\t��Ҫ��ӵ�ҩƷ���Ѵ��ڣ�\n");
				printf("\t\t\t\t�Ƿ����(Y/N)��");
			    if(toupper(getche())=='Y') m=1;
			    break;
			}
			t=t->next;
		}
		if(t==NULL) k=1;
		if(k==1||m==1)
		{
			fp=fopen("d:\\medfile.txt","at+");
			if(fp==NULL)
			{
				printf("\n\t\t\t\t�ļ���ʧ�ܣ�\n");
				getch();
				exit(1);
			}
			count++;
			printf("\n\t\t\t\t��ţ�");
			scanf("%d",&s->num);
			printf("\t\t\t\t��Ч��");
			scanf("%s",s->gx);
			printf("\t\t\t\t������"); 
			scanf("%d",&s->xl);
			printf("\t\t\t\t���"); 
			scanf("%s",s->type);
			printf("\t\t\t\t��������(��:2017-5-1)��");
			scanf("%s",s->scrq);
			printf("\t\t\t\t�����ڣ�");
			scanf("%s",s->bzq);
			printf("\t\t\t\t���ۣ�");
			scanf("%f",&s->price);
			printf("\t\t\t\t��棺"); 
			scanf("%d",&s->kc);
			fprintf(fp,"%d %s %s %d %s %s %s %f %d\n",s->num,s->name,s->gx,s->xl,s->type,s->scrq,s->bzq,s->price,s->kc);
			fclose(fp);
		}
		else 
		{
			free(s);
		}
		printf("\n\t\t\t\t�Ƿ������ӣ�Y/N����");
		if(toupper(getche())=='Y') flag=1;
		else flag=0;
		pHead=readfile();
		system("cls");
	}while(flag);
	return pHead;
}
void XG(struct med *pHead)       //�޸���Ϣ 
{
	int i,m,n=1,flag=1;
	struct med *p,*t;
	char name[N];
	int num;
	do
	{
		i=0;
		printf("\n\t\t\t���������޸ĵ�ҩƷ����"); 
		scanf("%s",name);
		t=pHead->next;
		while(t)
		{
			if(strcmp(name,t->name)==0)
			{
				if(n==1)
				{
					printf("----------------------------------------------------------------------------------------------------\n");
					printf("|  ���  |       ҩ��       |       ��Ч       | ���� |  ���  |  ��������  | ������ | ���� | ��� |\n");
					printf("----------------------------------------------------------------------------------------------------\n");
					n=0; 
				}
				printf("|%7d ",t->num);
				printf("|%17s ",t->name);
				printf("|%18s",t->gx);
				printf("|%6d",t->xl);
				printf("|%8s",t->type);
				printf("|%11s ",t->scrq);
				printf("|%7s ",t->bzq);
				printf("|%5.1f ",t->price);
				printf("|%5d |",t->kc);
				printf("\n");
				printf("----------------------------------------------------------------------------------------------------\n");
				i++;
				p=t;
			}
			t=t->next;
		} 
		if(i>1)
		{
			printf("\n\t\t\t��������Ҫ�޸ĵ�ҩƷ��ţ�");
			scanf("%d",&num);
			t=pHead->next;
			while(t)
			{
				if(t->num==num)
				{
					p=t;
					break;
				} 
				t=t->next;
			}	   
		}
		if(t==NULL&&n==1) printf("\t\t\tδ�ҵ�����Ҫ�޸ĵ�ҩƷ��\n");
		else 
		{
			printf("\t\t\t��Ҫ�޸ĵ��ǣ�\n");
			printf("----------------------------------------------------------------------\n");
			printf("|1.���||2.��Ч||3.����||4.���||5.��������||6.������||7.����||8.���|\n");
			printf("----------------------------------------------------------------------\n");
			scanf("%d",&m);
			switch(m)
			{
				case 1:printf("%s��ԭ��ţ�",p->name);
				       printf("%d.\t",p->num);
				       printf("��������±�ţ�");	
			           scanf("%d",&p->num); break;
				case 2:printf("%s��ԭ��Ч��",p->name);
				       printf("%s.\t",p->gx);
				       printf("��������¹�Ч��");	
			           scanf("%s",p->gx); break;
				case 3:printf("%s��ԭ������",p->name);
				       printf("%d.\t",p->xl);
				       printf("���������������");	
			           scanf("%d",&p->xl); break;
				case 4:printf("%s��ԭ���",p->name);
				       printf("%s.\t",p->type);
				       printf("������������");	
			           scanf("%s",p->type); break;
				case 5:printf("%s��ԭ�������ڣ�",p->name);
				       printf("%s.\t",p->scrq);
				       printf("����������������ڣ�");	
			           scanf("%s",p->scrq); break;
				case 6:printf("%s��ԭ�����ڣ�",p->name);
				       printf("%s.\t",p->bzq);
				       printf("��������±����ڣ�");	
			           scanf("%s",p->bzq); break;
	       		case 7:printf("%s��ԭ���ۣ�",p->name);
				       printf("%.1f.\t",p->price);
				       printf("��������µ��ۣ�");	
			           scanf("%f",&p->price); break;
	       		case 8:printf("%s��ԭ��棺",p->name);
				       printf("%d.\t",p->kc);
				       printf("��������¿�棺");	
			           scanf("%d",&p->kc); break;
				default: break;
			}
			print(pHead);
		}
		printf("\t\t\t�Ƿ�����޸ģ�Y/N����");
		if(toupper(getche())=='Y') 
		{
			flag=1;
			n=1;
			system("cls");
		}
		else flag=0;
	}while(flag);
	writefile(pHead);
}

struct med *SC(struct med *pHead)       //ɾ����Ϣ 
{
	int i,m,n=1,flag=1;
	struct med *p,*t,*s;
	char name[N];
	int num;
	do
	{
		i=0;
		printf("\n\t\t\t��������ɾ����ҩƷ����"); 
		scanf("%s",name);
		t=pHead->next;
		while(t)
		{
			if(strcmp(name,t->name)==0)
			{
				if(n==1)
				{
					printf("����Ҫɾ������Ϣ���£�\n");
					printf("----------------------------------------------------------------------------------------------------\n");
					printf("|  ���  |       ҩ��       |       ��Ч       | ���� |  ���  |  ��������  | ������ | ���� | ��� |\n");
					printf("----------------------------------------------------------------------------------------------------\n");
					n=0; 
				}
				printf("|%7d ",t->num);
				printf("|%17s ",t->name);
				printf("|%18s",t->gx);
				printf("|%6d",t->xl);
				printf("|%8s",t->type);
				printf("|%11s ",t->scrq);
				printf("|%7s ",t->bzq);
				printf("|%5.1f ",t->price);
				printf("|%5d |",t->kc);
				printf("\n");
				printf("----------------------------------------------------------------------------------------------------\n");
				s=t;
				i++;
			}
			t=t->next;
		}
		if(t==NULL&&n==1) printf("\t\t\tδ�ҵ�����Ҫɾ����ҩƷ��\n");
		else 
		{
			if(i>1)
			{
				printf("\n\t\t\t��������Ҫɾ����ҩƷ��ţ�");
				scanf("%d",&num);
				t=pHead->next;
				while(t)
				{
					if(t->num==num)
					{
						s=t;
						break;
					} 
					t=t->next;
				}	   
			}
			system("cls");
			printf("----------------------------------------------------------------------------------------------------\n");
			printf("|  ���  |       ҩ��       |       ��Ч       | ���� |  ���  |  ��������  | ������ | ���� | ��� |\n");
			printf("----------------------------------------------------------------------------------------------------\n");
			printf("|%7d ",s->num);
			printf("|%17s ",s->name);
			printf("|%18s",s->gx);
			printf("|%6d",s->xl);
			printf("|%8s",s->type);
			printf("|%11s ",s->scrq);
			printf("|%7s ",s->bzq);
			printf("|%5.1f ",s->price);
			printf("|%5d |",s->kc);
			printf("\n");
			printf("----------------------------------------------------------------------------------------------------\n");
			printf("\t\t\tȷ��ɾ����Ϣ(Y/N)?");
			if(toupper(getche())=='Y')
			{
				p=t=pHead;
				while(t)
				{
					if(t==s)
					{
						p->next=t->next;
						free(t);
						count--;
						break;	
					}	
					p=t;
					t=t->next;
				}
				print(pHead);  
			}
	        else printf("\t\t\t\t����ɾ����");
		}
		printf("\t\t\t�Ƿ�����޸ģ�Y/N����");
		if(toupper(getche())=='Y') 
		{
			flag=1;
			n=1;
			system("cls");
		}
		else flag=0;
	}while(flag);
	writefile(pHead);
	return pHead; 
}


struct med *NZ(struct med *pHead)
{
	struct med *p,*q,*t;
	q=p=pHead->next;
	t=p->next;
	p->next=NULL;
	while(t)
	{
		q=t;
		t=t->next;
		q->next=p;
		p=q;
	}
	pHead->next=q;
	return pHead;
}
struct med *namesort(struct med *pHead)
{
    struct med *p,*q;
    struct med d;
    q=pHead;
    for(q=q->next;q->next!=NULL;q=q->next)
    {
	    for(p=q->next;p!=NULL;p=p->next)
	    {
		    if(strcmp(q->name,p->name)>0)
		    {
		    	d.num=q->num;
		    	strcpy(d.name,q->name);
		    	strcpy(d.gx,q->gx);
		    	d.xl=q->xl;
		    	strcpy(d.type,q->type);
		    	strcpy(d.scrq,q->scrq);
		    	strcpy(d.bzq,q->bzq);
		    	d.price=q->price;
		    	d.kc=q->kc;
		    	
		    	q->num=p->num;
		    	strcpy(q->name,p->name);
		    	strcpy(q->gx,p->gx);
		    	q->xl=p->xl;
		    	strcpy(q->type,p->type);
		    	strcpy(q->scrq,p->scrq);
		    	strcpy(q->bzq,p->bzq);
		    	q->price=p->price;
		    	q->kc=p->kc;
		    	
		    	p->num=d.num;
		    	strcpy(p->name,d.name);
		    	strcpy(p->gx,d.gx);
		    	p->xl=d.xl;
		    	strcpy(p->type,d.type);
		    	strcpy(p->scrq,d.scrq);
		    	strcpy(p->bzq,d.bzq);
		    	p->price=d.price;
		    	p->kc=d.kc;
			}
		}
    }
    return pHead;
}
struct med *numsort(struct med *pHead)
{
    struct med *p,*q;
    struct med d;
    q=pHead;
    for(q=q->next;q->next!=NULL;q=q->next)
    {
	    for(p=q->next;p!=NULL;p=p->next)
	    {
		    if(q->num>p->num)
		    {
		    	d.num=q->num;
		    	strcpy(d.name,q->name);
		    	strcpy(d.gx,q->gx);
		    	d.xl=q->xl;
		    	strcpy(d.type,q->type);
		    	strcpy(d.scrq,q->scrq);
		    	strcpy(d.bzq,q->bzq);
		    	d.price=q->price;
		    	d.kc=q->kc;
		    	
		    	q->num=p->num;
		    	strcpy(q->name,p->name);
		    	strcpy(q->gx,p->gx);
		    	q->xl=p->xl;
		    	strcpy(q->type,p->type);
		    	strcpy(q->scrq,p->scrq);
		    	strcpy(q->bzq,p->bzq);
		    	q->price=p->price;
		    	q->kc=p->kc;
		    	
		    	p->num=d.num;
		    	strcpy(p->name,d.name);
		    	strcpy(p->gx,d.gx);
		    	p->xl=d.xl;
		    	strcpy(p->type,d.type);
		    	strcpy(p->scrq,d.scrq);
		    	strcpy(p->bzq,d.bzq);
		    	p->price=d.price;
		    	p->kc=d.kc;
			}
		}
    }
    return pHead;
}
struct med *xlsort(struct med *pHead)
{
    struct med *p,*q;
    struct med d;
    q=pHead;
    for(q=q->next;q->next!=NULL;q=q->next)
    {
	    for(p=q->next;p!=NULL;p=p->next)
	    {
		    if(q->xl>p->xl)
		    {
		    	d.num=q->num;
		    	strcpy(d.name,q->name);
		    	strcpy(d.gx,q->gx);
		    	d.xl=q->xl;
		    	strcpy(d.type,q->type);
		    	strcpy(d.scrq,q->scrq);
		    	strcpy(d.bzq,q->bzq);
		    	d.price=q->price;
		    	d.kc=q->kc;
		    	
		    	q->num=p->num;
		    	strcpy(q->name,p->name);
		    	strcpy(q->gx,p->gx);
		    	q->xl=p->xl;
		    	strcpy(q->type,p->type);
		    	strcpy(q->scrq,p->scrq);
		    	strcpy(q->bzq,p->bzq);
		    	q->price=p->price;
		    	q->kc=p->kc;
		    	
		    	p->num=d.num;
		    	strcpy(p->name,d.name);
		    	strcpy(p->gx,d.gx);
		    	p->xl,d.xl;
		    	strcpy(p->type,d.type);
		    	strcpy(p->scrq,d.scrq);
		    	strcpy(p->bzq,d.bzq);
		    	p->price=d.price;
		    	p->kc=d.kc;
			}
		}
    }
    return pHead;
}
void sort1(struct med *pHead)
{
	int m;
	pHead=namesort(pHead);
	printf("\n\t\t\t\t��ѡ��ҩ������/����"); 
	printf("|1.����|| 2.����|\n");
	printf("\t\t\t\t   �����룺"); 
	scanf("%d",&m);
	switch(m)
	{
		case 1: print(pHead); break;
		case 2: pHead=NZ(pHead);
	 	        print(pHead); break;
        default: printf("��������\n"); break;
	}
}
void sort2(struct med *pHead)
{
	int m;
	pHead=numsort(pHead);
	printf("\n\t\t\t\t��ѡ��������/����"); 
	printf("|1.����|| 2.����|\n");
	printf("\t\t\t\t   �����룺"); 
	scanf("%d",&m);
	switch(m)
	{
		case 1: print(pHead); break;
		case 2: pHead=NZ(pHead);
	 	        print(pHead); break;
        default: printf("��������\n"); break;
	}
}
void sort3(struct med *pHead)
{
	int m;
	pHead=xlsort(pHead);
	printf("\n\t\t\t\t��ѡ����������/����"); 
	printf("|1.����|| 2.����|\n");
	printf("\t\t\t\t   �����룺"); 
	scanf("%d",&m);
	switch(m)
	{
		case 1: print(pHead); break;
		case 2: pHead=NZ(pHead);
	 	        print(pHead); break;
        default: printf("��������\n"); break;
	}
}
void sort(struct med *pHead)
{
	int m,flag=1;
	do
	{
		printf("\n\t\t\t\t��ѡ������ʽ��"); 
		printf("|1.ҩ��|| 2.���||3.����|\n");
		printf("\t\t\t\t   �����룺"); 
		scanf("%d",&m);
		switch(m)
		{
			case 1:  sort1(pHead); break;
			case 2:  sort2(pHead); break;
			case 3:  sort3(pHead); break;
	        default: printf("��������\n"); break;
		}
		printf("\n\t\t\t\t�Ƿ���������ʽ�鿴��Y/N����");
		if(toupper(getche())=='Y') flag=1;
		else flag=0;
	}while(flag);
}

void Tongji(struct med *pHead)
{
	struct med *t;
	int i,j,k;
	long int sum=0;
	char type[N]="����ҩ";
	i=j=0;
	t=pHead->next;
	while(t)
	{
		sum+=t->kc;
		k=1;
		k=strcmp(type,t->type);
		t=t->next;
		if(k==0) i++;
		else j++;
	}
	printf("\t\t\t\t----------------------------------\n");
	printf("\t\t\t\t|       ***ҩƷͳ��***           |\n");
	printf("\t\t\t\t----------------------------------\n");
	printf("\t\t\t\t|      ҩƷ�ܿ����%-10ld.   |\n",sum);
	printf("\t\t\t\t----------------------------------\n");
	printf("\t\t\t\t|      ҩƷ�ܹ���%2d��.           |\n",count);
	printf("\t\t\t\t----------------------------------\n");
	printf("\t\t\t\t|      ����ҩ��%2d��.             |\n",i);
	printf("\t\t\t\t----------------------------------\n");
	printf("\t\t\t\t|      �Ǵ���ҩ��%2d��.           |\n",j);
	printf("\t\t\t\t----------------------------------\n");
} 


void MIMA()
{
	FILE *fp; 
	int i,j,t,c,m=4;
	int flag=1;
	char mm[7];
	char mima[7];
	char ch;
	fp=fopen("d:\\mima.txt","r");
	if(fp==NULL)
	{
		printf("\n�ļ���ʧ�ܣ�\n");
		getch();
		exit(1);
	}
	fscanf(fp,"%s",mm);
	fclose(fp);
	do
	{
		i=0;
		memset(mima,0,sizeof(mima));
		printf("\n\t\t\t\t������6λ���룺");	
		while((ch = getch())!='\r')
		{
			_flushall();
			if(i>=6)     //�����볬��6λ
			{	
				system("cls");
				memset(mima,0,sizeof(mima));
				i=0;
				printf("\t\t\t\t���볬��6λ��");
				printf("\t\t\t\t���ٴ�����6λ����: ");
				continue;
			}
			if(ch=='\b')
			{ 
				if(i>0)
				{
					i--;
					printf("\b \b");
					mima[i]=0;
					continue;
				}
				else
				{
					continue;
				}
			}
			else
			{
				mima[i]=ch;
				printf("*");
			}
			i++;
		}
		if(strcmp(mima,mm)==0) 
		{
			printf("\n\t\t\t\t�ɹ���½!\n");
			flag=0;
		}
		else
		{
			m--;
			if(m>0)
			{
				printf("\n\t\t\t\t������󣬵�¼ʧ�� !\n");
				system("cls");
				printf("\t\t\t\t�㻹��%d�λ��ᣡ\n",m);
				printf("\t\t\t\t�������������룺");
				flag=1;
			}
		    else
			{
				flag=0; 
				printf("\n\t\t\t\t������֤�����Ѵﵽ���\n");
				printf("\t\t\t\t------------------------------\n");
				printf("\t\t\t\t|         ***help:***        |\n");
				printf("\t\t\t\t------------------------------\n");
				printf("\t\t\t\t|1: �һ�����|    |2: �˳�ϵͳ|\n");
				printf("\t\t\t\t------------------------------\n");
				printf("\n\t\t\t\t��ѡ��");
				scanf("%d",&c);
				switch(c)
				{
					case 1:printf("\t\t\t\t�����õ������ǣ�(%s)\n", mm) ;
					       printf("\t\t\t\tϵͳ���˳���\n");
						   exit(1); break; 
					case 2:printf("\t\t\t\tϵͳ���˳���");exit(1); break;    
					default: exit(1); break;	
				}
			}
		}
	}while(flag);	
}
void XGMA()
{
	FILE *fp;
	int i,j,t;
	char mm[7];
	char m[7];
	char mima[7];
	fp=fopen("d:\\mima.txt","r");
	if(fp==NULL)
	{
		printf("\n�ļ���ʧ�ܣ�\n");
		getch();
		exit(1);
	}
	fscanf(fp,"%s",mm);
	fclose(fp);
	printf("\t\t\t\t������ԭ6λ���룺");	
	for(t=0;t<6;t++)
	{
   		mima[t]=getch();
		putch('*'); 
	}
	mima[6]='\0';
	getch();
	if(strcmp(mima,mm)==0) 
	{
		printf("\n\t\t\t\t��֤�ɹ�!\n");
		printf("\t\t\t\t�������޸ĵ�����(6λ,������ĸ���ִ�Сд):");
	    scanf("%s",m);
	    printf("\t\t\t\t��ȷ���Ƿ��޸�(Y/N)?");
	    if(toupper(getche())=='Y') 
	    {
    		fp=fopen("d:\\mima.txt","w");
			if(fp==NULL)
			{
				printf("\n�ļ���ʧ�ܣ�\n");
				getch();
				exit(1);
			}
			fprintf(fp,"%s",m);
			fclose(fp);
			printf("\t\t\t�����޸ĳɹ�!\n");
    	}
	}	
	else
	{
		printf("\n\t\t\t\t���������֤ʧ�� !\n");
		printf("����������������棡");
		getch(); 
	}
}

void GL()
{
	system("color 0f");
	int a;
	struct med *pHead;
	pHead=readfile();
//	MIMA();
	menu(); 
	while(scanf("%d",&a)!=EOF)
	{
		switch(a) 
		{
			case 1: pHead=Create(); break;             //����ҩƷ��Ϣ 
			case 2: pHead=readfile(); print(pHead); break;  //��ȡ�ļ���Ϣ����� 
			case 3: pHead=TJ(pHead); break;                  //���ҩƷ��Ϣ 
			case 4: CX(pHead); break;                  //����ҩƷ��Ϣ
			case 5: pHead=SC(pHead); break;            //ɾ��ҩƷ��Ϣ 
			case 6: XG(pHead); break;                  //�޸�ҩƷ��Ϣ
			case 7: sort(pHead); break;          //����ҩƷ��Ϣ 
			case 8: Tongji(pHead); break;              //ҩƷ��Ϣͳ�� 
			case 9: XGMA(); break;                     //�޸Ĺ���Ա���� 
			case 0: printf("\t\t\t\tϵͳ���˳���\n"); exit(1); break;    
			default:printf("\t\t\t\t����������������ȷָ�\n");break;
		}
		menu();
	}
}


//�û���������
struct med *YMGM(struct med *pHead,struct med *L)      //����Ź��� 
{
	int k,m,n;
	int flag=1;
	int num;
	char gx[N];
	struct med *t,*s,*p;
	icount=0;
	p=L;
	do
	{
		system("cls");
		printf("����ҩƷ��Ϣ���£�\n");
		pHead=readfile();
	 	print(pHead);
	 	k=m=n=1;
		printf("\n����������ҵĹ�Ч��"); 
		scanf("%s",gx);
		t=pHead->next;
		while(t)
		{
			if(strcmp(gx,t->gx)==0)
			{
				if(n==1)
				{
					printf("----------------------------------------------------------------------------------------------------\n");
					printf("|  ���  |       ҩ��       |       ��Ч       | ���� |  ���  |  ��������  | ������ | ���� | ��� |\n");
					printf("----------------------------------------------------------------------------------------------------\n");
					n=0; 
				}
				printf("|%7d ",t->num);
				printf("|%17s ",t->name);
				printf("|%18s",t->gx);
				printf("|%6d",t->xl);
				printf("|%8s",t->type);
				printf("|%11s ",t->scrq);
				printf("|%7s ",t->bzq);
				printf("|%5.1f ",t->price);
				printf("|%5d |",t->kc);
				printf("\n");
			  	printf("----------------------------------------------------------------------------------------------------\n");
				k=0;
			}
			t=t->next;
		} 
		if(t==NULL&&k==1) printf("\nδ�ҵ�����ҵ�ҩƷ��\n");
		else
		{
			printf("\n����������Ҫ�����ҩƷ��ţ�");
			scanf("%d",&num);
			t=pHead->next;
			while(t)
			{
				if(num==t->num)
				{
					printf("----------------------------------------------------------------------------------------------------\n");
					printf("|  ���  |       ҩ��       |       ��Ч       | ���� |  ���  |  ��������  | ������ | ���� | ��� |\n");
					printf("----------------------------------------------------------------------------------------------------\n");
					printf("|%7d ",t->num);
					printf("|%17s ",t->name);
					printf("|%18s",t->gx);
					printf("|%6d",t->xl);
					printf("|%8s",t->type);
					printf("|%11s ",t->scrq);
					printf("|%7s ",t->bzq);
					printf("|%5.1f ",t->price);
					printf("|%5d |",t->kc);
					printf("\n");
				  	printf("----------------------------------------------------------------------------------------------------\n");
				  	m=0;
				  	printf("\n�Ƿ���빺�ﳵ��Y/N����");
					if(toupper(getche())=='Y') 
					{
						s=(struct med *)malloc(sizeof(struct med));
						s->num=t->num;
				    	strcpy(s->name,t->name);
				    	strcpy(s->gx,t->gx);
				    	s->xl=t->xl;
				    	strcpy(s->type,t->type);
				    	strcpy(s->scrq,t->scrq);
				    	strcpy(s->bzq,t->bzq);
				    	s->price=t->price;
				    	s->kc=t->kc;
						p->next=s;
						p=s;
						s->next=NULL;
						icount++;
						break;
					}
					else break;	
				}
				t=t->next;
			} 
			if(t==NULL&&m==1) printf("\nδ�ҵ�����ҵ�ҩƷ��\n");
		}
		printf("\n�Ƿ����ѡ����Y/N����");
		if(toupper(getche())=='Y') flag=1;
		else flag=0;
	}while(flag);
	if(L->next!=NULL)
	{
		print(L);
	}
	printf("\n�Ƿ���빺�ﳵ��Y/N����");
	if(toupper(getche())=='Y') L=GWC(pHead,L); 
	return L;
}
struct med *BHGM(struct med *pHead,struct med *L)      //����Ź��� 
{
	int m;
	int flag=1;
	int num;
	char gx[N];
	struct med *t,*s,*p;
	icount=0;
	p=L;
	do
	{
		system("cls");
		printf("����ҩƷ��Ϣ���£�\n");
		pHead=readfile();
	 	print(pHead);
	 	m=1;
		printf("\n����������Ҫ�����ҩƷ��ţ�");
		scanf("%d",&num);
		t=pHead->next;
		while(t)
		{
			if(num==t->num)
			{
				printf("----------------------------------------------------------------------------------------------------\n");
				printf("|  ���  |       ҩ��       |       ��Ч       | ���� |  ���  |  ��������  | ������ | ���� | ��� |\n");
				printf("----------------------------------------------------------------------------------------------------\n");
				printf("|%7d ",t->num);
				printf("|%17s ",t->name);
				printf("|%18s",t->gx);
				printf("|%6d",t->xl);
				printf("|%8s",t->type);
				printf("|%11s ",t->scrq);
				printf("|%7s ",t->bzq);
				printf("|%5.1f ",t->price);
				printf("|%5d |",t->kc);
				printf("\n");
			  	printf("----------------------------------------------------------------------------------------------------\n");
			  	m=0;
			  	printf("\n�Ƿ���빺�ﳵ��Y/N����");
				if(toupper(getche())=='Y') 
				{
					s=(struct med *)malloc(sizeof(struct med));
					s->num=t->num;
			    	strcpy(s->name,t->name);
			    	strcpy(s->gx,t->gx);
			    	s->xl=t->xl;
			    	strcpy(s->type,t->type);
			    	strcpy(s->scrq,t->scrq);
			    	strcpy(s->bzq,t->bzq);
			    	s->price=t->price;
			    	s->kc=t->kc;
					p->next=s;
					p=s;
					s->next=NULL;
					icount++;
					break;
				}
				else break;	
			}
			t=t->next;
		} 
		if(t==NULL&&m==1) printf("\nδ�ҵ�����ҵ�ҩƷ��\n");
		printf("\n�Ƿ����ѡ����Y/N����");
		if(toupper(getche())=='Y') flag=1;
		else flag=0;
	}while(flag);
	/*if(L->next!=NULL)
	{
		print(L);
	}*/
	printf("\n�Ƿ���빺�ﳵ��Y/N����");
	if(toupper(getche())=='Y') L=GWC(pHead,L); 
	return L;
}
struct med *GM(struct med *pHead,struct med *L)
{
	int c;
	printf("\t\t\t�������㹺��ķ�ʽ��\t");
	printf("|1.���|  |2.��Ч|");
	scanf("%d",&c);
	switch(c)
	{
		case 1: L=BHGM(pHead,L); break;
		case 2: L=YMGM(pHead,L); break;
		default:  break;
	}
	return L;
}

struct med *YMSC(struct med *L,int num)
{
	struct med *t,*p;
	p=t=L;
	while(t)
	{
		if(t->num==num)
		{
			p->next=t->next;
			free(t);
			icount--;
			break;	
		}	
		p=t;
		t=t->next;
	}
	return L;
} 

struct med *GMXG(struct med *pHead,int num,int i,int d[]) 
{

	struct med *t,*p;
	t=pHead->next;
	while(t)
	{
		if(num==t->num)
		{
			t->xl+=d[i];
			t->kc-=d[i];	
		}
		t=t->next;
	}
	return pHead;
}
struct med *GWC(struct med *pHead,struct med *L)
{
	struct med *t,*p; 
	int i=0,j,c=1,d[N];
	int num;
	int sum=0;
	float m=0;
	t=L->next;
	for(i=0;i<icount;i++)
	{
	 	d[i]=1;
	}
	if(t==NULL)
	{
		printf("\t\t\t\t���ﳵ��ҩƷ��");
	}
	else
	{
		printf("\n\t\t\t------------------------------------------------\n"); 
		printf("\t\t\t|           ***���ﳵ(����%2d��ҩ)***           |\n",icount);
		printf("\t\t\t------------------------------------------------\n");
		printf("\t\t\t| ��� |       ҩƷ��     | ��� | ���� | ���� |\n");
		printf("\t\t\t------------------------------------------------\n");
		i=0;
		while(t)
		{
			printf("\t\t\t");
			printf("|%5d ",t->num);
			printf("|%17s ",t->name); 
			printf("|%5d ",t->kc);
			printf("|%5.1f ",t->price);
			printf("|%5d |",d[i]);
			printf("\n");
			printf("\t\t\t------------------------------------------------\n");
			i++;
			t=t->next;
		}
		printf("\t\t\t��ȷ��ҩƷ����!�Ƿ��޸�(Y/N)?");
		if(toupper(getche())=='Y')
		{
			printf("\n\t\t\t�������Ʒ��ţ�"); 
			scanf("%d",&num);
			while(c)
			{
				i=0;
				t=L->next;
				while(t)
				{
					i++;
					if(t->num==num)
					{
						p=t;
						break;	
					}
					t=t->next;
				}
				
				printf("\t\t\t%s��ԭ����Ϊ%d.",p->name,d[i-1]);
				printf("\t�������޸�ֵ��"); 
				scanf("%d",&d[i-1]);
				printf("\t\t\t%s���޸ĺ�����Ϊ%d.",p->name,d[i-1]);
				if(d[i-1]==0)
				{  
					L=YMSC(L,num);
					for(j=i-1;j<icount;j++)
					{
						d[j]=d[j+1];
					}
				}
				printf("�Ƿ�����޸�(Y/N)?");
				if(toupper(getche())=='Y')
				{
					printf("\n\t\t\t�������Ʒ��ţ�");
					scanf("%d",&num);
					c=1;
				}
				else c=0;
			}
		}
		printf("\n\t\t\t�㹺���ҩƷ���£�\n");
		printf("\t\t\t------------------------------------------------\n"); 
		printf("\t\t\t|           ***���ﳵ(����%2d��ҩ)***           |\n",icount);
		printf("\t\t\t------------------------------------------------\n");
		printf("\t\t\t| ��� |       ҩƷ��     | ��� | ���� | ���� |\n");
		printf("\t\t\t------------------------------------------------\n");
		t=L->next;
		if(t==NULL)
		{
			printf("\t\t\t���ﳵ����ҩƷ��");
			printf("\t\t\t�Ƿ�����ѡ��(Y/N)?");
	        if(toupper(getche())=='Y')
			{
				system("cls");
				YH(); 
			}
			else exit(1);
		}
		else
		{
			i=0;
			while(t)
			{
				printf("\t\t\t|%5d ",t->num);
				printf("|%17s ",t->name); 
				printf("|%5d ",t->kc);
				printf("|%5.1f ",t->price);
				printf("|%5d |",d[i]);
				printf("\n");
				printf("\t\t\t------------------------------------------------\n");
				sum+=d[i];
				m+=t->price*d[i]*1.0;
				i++;
				t=t->next;
			}
		}
		printf("\t\t\t�ܼ�%d��ҩƷ����%.1fԪ.\n",sum,m);
		printf("\t\t\t�Ƿ�ȷ�Ϲ���(Y/N)?");
		if(toupper(getche())=='Y')
		{
			t=L->next;
			i=0;
			while(t)
			{
				pHead=GMXG(pHead,t->num,i,d);
				i++;
				t=t->next;
			}
			writefile(pHead);
			//pHead=readfile();
			//print(pHead);
			printf("\t\t\t\t������ɣ�\n");
		}
		else
		{
			printf("\t\t\t\n��������\n");
		}
		L->next=NULL;
	}
	icount=0;
	printf("\n\t\t\t\t������˳���");
	getch();
	return L;
}

void YH()
{
	system("color f0");
	struct med *L;
	struct med *pHead;
	L=(struct med *)malloc(sizeof(struct med));
	L->next=NULL;
	int c=1;
	do{
		system("cls");
		printf("\t\t\t\t------------------------------\n");
		printf("\t\t\t\t|********ҩƷ����ϵͳ********|\n");
		printf("\t\t\t\t------------------------------\n");
		printf("\t\t\t\t|        1.ѡ��ҩƷ          |\n");
		printf("\t\t\t\t|        2.�� �� ��          |\n");
		printf("\t\t\t\t|        0.�˳�ϵͳ          |\n");
		printf("\t\t\t\t------------------------------\n");
		printf("\t\t\t\t��ѡ��");
		scanf("%d",&c);
		switch(c)
		{
			case 1: pHead=readfile();
					L=GM(pHead,L); break;
			case 2: L=GWC(pHead,L); break;
			case 0: exit(1); break; 
			default: printf("\t\t\t\t��������������ѡ��:"); break;
		}
		system("cls");
	}while(c); 	
} 

int main()
{
	GL();
	int c=1;
	do{ 
		system("color b0");
		printf("\t\t\t\t------------------------------\n");
		printf("\t\t\t\t|********ҩ�����ϵͳ********|\n");
		printf("\t\t\t\t------------------------------\n");
		printf("\t\t\t\t|       1.��½����ϵͳ       |\n");
		printf("\t\t\t\t|       2.���빺��ϵͳ       |\n");
		printf("\t\t\t\t|       0. �� �� ϵ ͳ       |\n");
		printf("\t\t\t\t------------------------------\n");
		printf("\t\t\t\t\t��ѡ���½��");
		scanf("%d",&c);
		switch(c)
		{
			case 1: GL(); break;
			case 2: YH(); break;
			case 0: printf("\t\t\t\tϵͳ���˳���\n"); break; 
			default: printf("\t\t\t\t��������������ѡ��:"); break;
		}
	}while(c); 
}
