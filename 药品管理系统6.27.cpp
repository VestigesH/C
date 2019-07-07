#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define N 50 

struct med 
{
	int  num;        //编码 
	char name[N];    //药名
	char gx[N];      //功效 
	int  xl;         //销量  
	char type[N];    //类别 
	char scrq[N];    //生产日期
	char bzq[N];     //保质期 
	float price;     //单价 
	int  kc;         //库存 
	struct med *next;  //指针域 
};               //药品信息结构体 
int count;           //记录药品个数
int icount; 

struct med *readfile();
void menu()     //菜单函数 
{
	printf("\n\t\t\t\t按任意键继续！");
	getch();
	system("cls"); 
	printf("\n");
	printf("\n\t\t\t************药店管理系统：当前有%2d种药的信息************\n",count);
	printf("\t\t\t*                1.录入药品信息                        *\n");
	printf("\t\t\t*                2.显示所有信息                        *\n");
	printf("\t\t\t*                3.添加药品信息                        *\n");
	printf("\t\t\t*                4.查找药品信息                        *\n");
	printf("\t\t\t*                5.删除药品信息                        *\n"); 
	printf("\t\t\t*                6.修改药品信息                        *\n"); 
	printf("\t\t\t*                7.药品信息排序                        *\n"); 
	printf("\t\t\t*                8.统计药品信息                        *\n");
	printf("\t\t\t*                9.修改管理密码                        *\n");
	printf("\t\t\t*                0.   退   出                          *\n");
	printf("\t\t\t********************************************************\n");
	printf("\t\t\t\t\t请选择一个功能（0-9）："); 
}
void writefile(struct med *pHead);    //写入文件函数 
struct med *GWC(struct med *pHead,struct med *L);
void YH();
struct med *Create()  //创建信息并保存在文件 
{
	struct med *pHead;
	struct med *p,*pNew;
	count=0;
	pHead=(struct med *)malloc(sizeof(struct med)); //为头节点申请内存空间 
	pHead->next=pHead;          //创建一个空链表 
	p=pHead;
	printf("\n请依次输入药品信息（以编号0结束）：\n");
	while(1)
	{
		count++;
		printf("\n请输入第%d个药品的信息：\n",count);	
		pNew=(struct med *)malloc(sizeof(struct med));
		printf("编号：");
		scanf("%d",&pNew->num);
		if(pNew->num==0) break;
		printf("药名："); 
		scanf("%s",pNew->name);
		printf("功效：");
		scanf("%s",pNew->gx);
		printf("销量："); 
		scanf("%d",&pNew->xl);
		printf("类别："); 
		scanf("%s",pNew->type);
		printf("生产日期(例:2017-5-1)：");
		scanf("%s",pNew->scrq);
		printf("保质期：");
		scanf("%s",pNew->bzq);
		printf("单价：");
		scanf("%f",&pNew->price);
		printf("库存：");
		scanf("%d",&pNew->kc);
		pNew->next=NULL;
		p->next=pNew;
		p=pNew;
		system("cls");	
	}             //创建单链表 
	count=count-1;     //统计输入总数 
	free(pNew);     //释放节点 
	writefile(pHead);
	printf("信息创建完成！\n"); 
	return pHead;
}
void print(struct med *pHead)  //输出信息 
{ 
	struct med *t;
	t=pHead->next;
	if(t==NULL)
	{
		printf("\n当前没有药品信息！\n");
		printf("是否录入信息(Y/N)?\n");
		if(toupper(getche())=='Y')  Create();
	}
	else
	{
		printf("\n----------------------------------------------------------------------------------------------------\n");
		printf("|                          ****药品管理系统：当前有%2d种药品信息****                                |\n",count);
		printf("----------------------------------------------------------------------------------------------------\n"); 
		printf("|  编号  |       药名       |       功效       | 销量 |  类别  |  生产日期  | 保质期 | 单价 | 库存 |\n");
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
void writefile(struct med *pHead)  //写入文件 
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
	printf("\n\t\t\t\t写入文件成功！\n");
}
struct med *readfile()     //读取文件信息 
{
	struct med *pHead;
	struct med *p,*pNew;
	FILE *fp;
	count=0;
	fp=fopen("d:\\medfile.txt","r");
	if(fp==NULL)
	{
		printf("\n\t\t\t\t文件打开失败！\n");
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
	printf("\n\t\t\t\t读取文件成功！\n");
	return pHead;	
}


void YMCX(struct med *pHead)      //按药名查询信息 
{
	int m=1,n=1;
	int flag=1;
	struct med *t;
	char name[N];
	system("cls");
	printf("\n\t\t\t\t请输入你查找的药名："); 
	scanf("%s",name);
	t=pHead->next;
	while(t)
	{
		if(strcmp(name,t->name)==0)
		{
			if(n==1)
			{
				printf("----------------------------------------------------------------------------------------------------\n");
				printf("|  编号  |       药名       |       功效       | 销量 |  类别  |  生产日期  | 保质期 | 单价 | 库存 |\n");
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
	if(t==NULL&&m==1) printf("\n\t\t\t\t未找到你查找的药品。\n"); 
}
void BHCX(struct med *pHead)      //按编号查询信息 
{
	int k,m=1,n=1;
	int flag=1;
	int num;
	struct med *t;
	system("cls");
	printf("\n\t\t\t\t请输入你查找的编号："); 
	scanf("%d",&num);
	t=pHead->next;
	while(t)
	{
		if(t->num==num)
		{
			if(n==1)
			{
				printf("----------------------------------------------------------------------------------------------------\n");
				printf("|  编号  |       药名       |       功效       | 销量 |  类别  |  生产日期  | 保质期 | 单价 | 库存 |\n");
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
	if(t==NULL&&m==1) printf("\n\t\t\t\t未找到你查找的药品。\n");
}
void GXCX(struct med *pHead)      //按功效查询信息 
{
	int m=1,n=1;
	int flag=1;
	struct med *t;
	char gx[N];
	system("cls");
	printf("\n\t\t\t\t请输入你查找的功效："); 
	scanf("%s",gx);
	t=pHead->next;
	while(t)
	{
		if(strcmp(gx,t->gx)==0)
		{
			if(n==1)
			{
				printf("----------------------------------------------------------------------------------------------------\n");
				printf("|  编号  |       药名       |       功效       | 销量 |  类别  |  生产日期  | 保质期 | 单价 | 库存 |\n");
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
	if(t==NULL&&m==1) printf("\n\t\t\t\t未找到你查找的药品。\n");
}
void KCCX(struct med *pHead)
{
	int k=1,n=1;
	int flag=1;
	struct med *t;
	int kc;
	system("cls");
	printf("\n\t\t\t\t请输入你查找的药品库存："); 
	scanf("%d",&kc);
	t=pHead->next;
	while(t)
	{
		if(t->kc>=kc)
		{
			if(n==1)
			{
				printf("----------------------------------------------------------------------------------------------------\n");
				printf("|  编号  |       药名       |       功效       | 销量 |  类别  |  生产日期  | 保质期 | 单价 | 库存 |\n");
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
	if(t==NULL&&k==1) printf("\n\t\t\t\t未找到你查找的药品。\n");
}
void CX(struct med *pHead)
{
	int c,flag=1;
	do
	{
		system("cls");
		printf("\t\t\t请选择你查询的方式：\n");
		printf("\t\t\t----------------------------------------\n"); 
		printf("\t\t\t|1.药名|   |2.编号|   |3.功效|   |4.库存|\n");
		printf("\t\t\t----------------------------------------\n");
		printf("\t\t\t请输入：");
		scanf("%d",&c);
		switch(c)
		{
			case 1:YMCX(pHead); break;
			case 2:BHCX(pHead); break;
			case 3:GXCX(pHead); break; 
			case 4:KCCX(pHead); break;
			default:printf("\t\t\t\t输入有误！\n"); break;
		}
		printf("\n\t\t\t\t是否继续查找（Y/N）：");
		if(toupper(getche())=='Y') flag=1;
		else flag=0;
	}while(flag);
}

struct med *TJ(struct med *pHead)     //添加信息 
{
	struct med *s,*t,*p;
	int k,m,flag;
	FILE *fp;
	do
	{
		k=m=0; 
		s=(struct med *)malloc(sizeof(struct med));
		printf("\n\t\t\t\t请输入你添加的药品信息：\n"); 
		printf("\t\t\t\t药名：");
		scanf("%s",s->name);
		t=pHead->next; 
		while(t)
		{
			if(strcmp(s->name,t->name)==0)
			{
				printf("\t\t\t\t需要添加的药品名已存在！\n");
				printf("\t\t\t\t是否添加(Y/N)？");
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
				printf("\n\t\t\t\t文件打开失败！\n");
				getch();
				exit(1);
			}
			count++;
			printf("\n\t\t\t\t编号：");
			scanf("%d",&s->num);
			printf("\t\t\t\t功效：");
			scanf("%s",s->gx);
			printf("\t\t\t\t销量："); 
			scanf("%d",&s->xl);
			printf("\t\t\t\t类别："); 
			scanf("%s",s->type);
			printf("\t\t\t\t生产日期(例:2017-5-1)：");
			scanf("%s",s->scrq);
			printf("\t\t\t\t保质期：");
			scanf("%s",s->bzq);
			printf("\t\t\t\t单价：");
			scanf("%f",&s->price);
			printf("\t\t\t\t库存："); 
			scanf("%d",&s->kc);
			fprintf(fp,"%d %s %s %d %s %s %s %f %d\n",s->num,s->name,s->gx,s->xl,s->type,s->scrq,s->bzq,s->price,s->kc);
			fclose(fp);
		}
		else 
		{
			free(s);
		}
		printf("\n\t\t\t\t是否继续添加（Y/N）：");
		if(toupper(getche())=='Y') flag=1;
		else flag=0;
		pHead=readfile();
		system("cls");
	}while(flag);
	return pHead;
}
void XG(struct med *pHead)       //修改信息 
{
	int i,m,n=1,flag=1;
	struct med *p,*t;
	char name[N];
	int num;
	do
	{
		i=0;
		printf("\n\t\t\t请输入你修改的药品名："); 
		scanf("%s",name);
		t=pHead->next;
		while(t)
		{
			if(strcmp(name,t->name)==0)
			{
				if(n==1)
				{
					printf("----------------------------------------------------------------------------------------------------\n");
					printf("|  编号  |       药名       |       功效       | 销量 |  类别  |  生产日期  | 保质期 | 单价 | 库存 |\n");
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
			printf("\n\t\t\t请输入需要修改的药品编号：");
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
		if(t==NULL&&n==1) printf("\t\t\t未找到你需要修改的药品。\n");
		else 
		{
			printf("\t\t\t你要修改的是？\n");
			printf("----------------------------------------------------------------------\n");
			printf("|1.编号||2.功效||3.销量||4.类别||5.生产日期||6.保质期||7.单价||8.库存|\n");
			printf("----------------------------------------------------------------------\n");
			scanf("%d",&m);
			switch(m)
			{
				case 1:printf("%s的原编号：",p->name);
				       printf("%d.\t",p->num);
				       printf("请输入的新编号：");	
			           scanf("%d",&p->num); break;
				case 2:printf("%s的原功效：",p->name);
				       printf("%s.\t",p->gx);
				       printf("请输入的新功效：");	
			           scanf("%s",p->gx); break;
				case 3:printf("%s的原销量：",p->name);
				       printf("%d.\t",p->xl);
				       printf("请输入的新销量：");	
			           scanf("%d",&p->xl); break;
				case 4:printf("%s的原类别：",p->name);
				       printf("%s.\t",p->type);
				       printf("请输入的新类别：");	
			           scanf("%s",p->type); break;
				case 5:printf("%s的原生产日期：",p->name);
				       printf("%s.\t",p->scrq);
				       printf("请输入的新生产日期：");	
			           scanf("%s",p->scrq); break;
				case 6:printf("%s的原保质期：",p->name);
				       printf("%s.\t",p->bzq);
				       printf("请输入的新保质期：");	
			           scanf("%s",p->bzq); break;
	       		case 7:printf("%s的原单价：",p->name);
				       printf("%.1f.\t",p->price);
				       printf("请输入的新单价：");	
			           scanf("%f",&p->price); break;
	       		case 8:printf("%s的原库存：",p->name);
				       printf("%d.\t",p->kc);
				       printf("请输入的新库存：");	
			           scanf("%d",&p->kc); break;
				default: break;
			}
			print(pHead);
		}
		printf("\t\t\t是否继续修改（Y/N）：");
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

struct med *SC(struct med *pHead)       //删除信息 
{
	int i,m,n=1,flag=1;
	struct med *p,*t,*s;
	char name[N];
	int num;
	do
	{
		i=0;
		printf("\n\t\t\t请输入你删除的药品名："); 
		scanf("%s",name);
		t=pHead->next;
		while(t)
		{
			if(strcmp(name,t->name)==0)
			{
				if(n==1)
				{
					printf("你需要删除的信息如下：\n");
					printf("----------------------------------------------------------------------------------------------------\n");
					printf("|  编号  |       药名       |       功效       | 销量 |  类别  |  生产日期  | 保质期 | 单价 | 库存 |\n");
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
		if(t==NULL&&n==1) printf("\t\t\t未找到你需要删除的药品。\n");
		else 
		{
			if(i>1)
			{
				printf("\n\t\t\t请输入需要删除的药品编号：");
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
			printf("|  编号  |       药名       |       功效       | 销量 |  类别  |  生产日期  | 保质期 | 单价 | 库存 |\n");
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
			printf("\t\t\t确认删除信息(Y/N)?");
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
	        else printf("\t\t\t\t放弃删除！");
		}
		printf("\t\t\t是否继续修改（Y/N）：");
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
	printf("\n\t\t\t\t请选择药名升序/降序："); 
	printf("|1.升序|| 2.降序|\n");
	printf("\t\t\t\t   请输入："); 
	scanf("%d",&m);
	switch(m)
	{
		case 1: print(pHead); break;
		case 2: pHead=NZ(pHead);
	 	        print(pHead); break;
        default: printf("输入有误！\n"); break;
	}
}
void sort2(struct med *pHead)
{
	int m;
	pHead=numsort(pHead);
	printf("\n\t\t\t\t请选择编号升序/降序"); 
	printf("|1.升序|| 2.降序|\n");
	printf("\t\t\t\t   请输入："); 
	scanf("%d",&m);
	switch(m)
	{
		case 1: print(pHead); break;
		case 2: pHead=NZ(pHead);
	 	        print(pHead); break;
        default: printf("输入有误！\n"); break;
	}
}
void sort3(struct med *pHead)
{
	int m;
	pHead=xlsort(pHead);
	printf("\n\t\t\t\t请选择销量升序/降序："); 
	printf("|1.升序|| 2.降序|\n");
	printf("\t\t\t\t   请输入："); 
	scanf("%d",&m);
	switch(m)
	{
		case 1: print(pHead); break;
		case 2: pHead=NZ(pHead);
	 	        print(pHead); break;
        default: printf("输入有误！\n"); break;
	}
}
void sort(struct med *pHead)
{
	int m,flag=1;
	do
	{
		printf("\n\t\t\t\t请选择排序方式："); 
		printf("|1.药名|| 2.编号||3.销量|\n");
		printf("\t\t\t\t   请输入："); 
		scanf("%d",&m);
		switch(m)
		{
			case 1:  sort1(pHead); break;
			case 2:  sort2(pHead); break;
			case 3:  sort3(pHead); break;
	        default: printf("输入有误！\n"); break;
		}
		printf("\n\t\t\t\t是否按其他排序方式查看（Y/N）：");
		if(toupper(getche())=='Y') flag=1;
		else flag=0;
	}while(flag);
}

void Tongji(struct med *pHead)
{
	struct med *t;
	int i,j,k;
	long int sum=0;
	char type[N]="处方药";
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
	printf("\t\t\t\t|       ***药品统计***           |\n");
	printf("\t\t\t\t----------------------------------\n");
	printf("\t\t\t\t|      药品总库存有%-10ld.   |\n",sum);
	printf("\t\t\t\t----------------------------------\n");
	printf("\t\t\t\t|      药品总共有%2d种.           |\n",count);
	printf("\t\t\t\t----------------------------------\n");
	printf("\t\t\t\t|      处方药有%2d种.             |\n",i);
	printf("\t\t\t\t----------------------------------\n");
	printf("\t\t\t\t|      非处方药有%2d种.           |\n",j);
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
		printf("\n文件打开失败！\n");
		getch();
		exit(1);
	}
	fscanf(fp,"%s",mm);
	fclose(fp);
	do
	{
		i=0;
		memset(mima,0,sizeof(mima));
		printf("\n\t\t\t\t请输入6位密码：");	
		while((ch = getch())!='\r')
		{
			_flushall();
			if(i>=6)     //当密码超过6位
			{	
				system("cls");
				memset(mima,0,sizeof(mima));
				i=0;
				printf("\t\t\t\t密码超出6位！");
				printf("\t\t\t\t请再次输入6位密码: ");
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
			printf("\n\t\t\t\t成功登陆!\n");
			flag=0;
		}
		else
		{
			m--;
			if(m>0)
			{
				printf("\n\t\t\t\t密码错误，登录失败 !\n");
				system("cls");
				printf("\t\t\t\t你还有%d次机会！\n",m);
				printf("\t\t\t\t请重新输入密码：");
				flag=1;
			}
		    else
			{
				flag=0; 
				printf("\n\t\t\t\t密码验证次数已达到最大！\n");
				printf("\t\t\t\t------------------------------\n");
				printf("\t\t\t\t|         ***help:***        |\n");
				printf("\t\t\t\t------------------------------\n");
				printf("\t\t\t\t|1: 找回密码|    |2: 退出系统|\n");
				printf("\t\t\t\t------------------------------\n");
				printf("\n\t\t\t\t请选择：");
				scanf("%d",&c);
				switch(c)
				{
					case 1:printf("\t\t\t\t你设置的密码是：(%s)\n", mm) ;
					       printf("\t\t\t\t系统将退出！\n");
						   exit(1); break; 
					case 2:printf("\t\t\t\t系统已退出！");exit(1); break;    
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
		printf("\n文件打开失败！\n");
		getch();
		exit(1);
	}
	fscanf(fp,"%s",mm);
	fclose(fp);
	printf("\t\t\t\t请输入原6位密码：");	
	for(t=0;t<6;t++)
	{
   		mima[t]=getch();
		putch('*'); 
	}
	mima[6]='\0';
	getch();
	if(strcmp(mima,mm)==0) 
	{
		printf("\n\t\t\t\t验证成功!\n");
		printf("\t\t\t\t请输你修改的密码(6位,如有字母区分大小写):");
	    scanf("%s",m);
	    printf("\t\t\t\t请确认是否修改(Y/N)?");
	    if(toupper(getche())=='Y') 
	    {
    		fp=fopen("d:\\mima.txt","w");
			if(fp==NULL)
			{
				printf("\n文件打开失败！\n");
				getch();
				exit(1);
			}
			fprintf(fp,"%s",m);
			fclose(fp);
			printf("\t\t\t密码修改成功!\n");
    	}
	}	
	else
	{
		printf("\n\t\t\t\t密码错误，验证失败 !\n");
		printf("按任意键返回主界面！");
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
			case 1: pHead=Create(); break;             //创建药品信息 
			case 2: pHead=readfile(); print(pHead); break;  //读取文件信息并输出 
			case 3: pHead=TJ(pHead); break;                  //添加药品信息 
			case 4: CX(pHead); break;                  //查找药品信息
			case 5: pHead=SC(pHead); break;            //删除药品信息 
			case 6: XG(pHead); break;                  //修改药品信息
			case 7: sort(pHead); break;          //排序药品信息 
			case 8: Tongji(pHead); break;              //药品信息统计 
			case 9: XGMA(); break;                     //修改管理员密码 
			case 0: printf("\t\t\t\t系统已退出！\n"); exit(1); break;    
			default:printf("\t\t\t\t输入有误！请输入正确指令。\n");break;
		}
		menu();
	}
}


//用户函数部分
struct med *YMGM(struct med *pHead,struct med *L)      //按编号购买 
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
		printf("所有药品信息如下：\n");
		pHead=readfile();
	 	print(pHead);
	 	k=m=n=1;
		printf("\n请输入你查找的功效："); 
		scanf("%s",gx);
		t=pHead->next;
		while(t)
		{
			if(strcmp(gx,t->gx)==0)
			{
				if(n==1)
				{
					printf("----------------------------------------------------------------------------------------------------\n");
					printf("|  编号  |       药名       |       功效       | 销量 |  类别  |  生产日期  | 保质期 | 单价 | 库存 |\n");
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
		if(t==NULL&&k==1) printf("\n未找到你查找的药品。\n");
		else
		{
			printf("\n请输入你需要购买的药品编号：");
			scanf("%d",&num);
			t=pHead->next;
			while(t)
			{
				if(num==t->num)
				{
					printf("----------------------------------------------------------------------------------------------------\n");
					printf("|  编号  |       药名       |       功效       | 销量 |  类别  |  生产日期  | 保质期 | 单价 | 库存 |\n");
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
				  	printf("\n是否加入购物车（Y/N）：");
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
			if(t==NULL&&m==1) printf("\n未找到你查找的药品。\n");
		}
		printf("\n是否继续选购（Y/N）：");
		if(toupper(getche())=='Y') flag=1;
		else flag=0;
	}while(flag);
	if(L->next!=NULL)
	{
		print(L);
	}
	printf("\n是否进入购物车（Y/N）：");
	if(toupper(getche())=='Y') L=GWC(pHead,L); 
	return L;
}
struct med *BHGM(struct med *pHead,struct med *L)      //按编号购买 
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
		printf("所有药品信息如下：\n");
		pHead=readfile();
	 	print(pHead);
	 	m=1;
		printf("\n请输入你需要购买的药品编号：");
		scanf("%d",&num);
		t=pHead->next;
		while(t)
		{
			if(num==t->num)
			{
				printf("----------------------------------------------------------------------------------------------------\n");
				printf("|  编号  |       药名       |       功效       | 销量 |  类别  |  生产日期  | 保质期 | 单价 | 库存 |\n");
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
			  	printf("\n是否加入购物车（Y/N）：");
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
		if(t==NULL&&m==1) printf("\n未找到你查找的药品。\n");
		printf("\n是否继续选购（Y/N）：");
		if(toupper(getche())=='Y') flag=1;
		else flag=0;
	}while(flag);
	/*if(L->next!=NULL)
	{
		print(L);
	}*/
	printf("\n是否进入购物车（Y/N）：");
	if(toupper(getche())=='Y') L=GWC(pHead,L); 
	return L;
}
struct med *GM(struct med *pHead,struct med *L)
{
	int c;
	printf("\t\t\t请输入你购买的方式：\t");
	printf("|1.编号|  |2.功效|");
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
		printf("\t\t\t\t购物车无药品！");
	}
	else
	{
		printf("\n\t\t\t------------------------------------------------\n"); 
		printf("\t\t\t|           ***购物车(共有%2d种药)***           |\n",icount);
		printf("\t\t\t------------------------------------------------\n");
		printf("\t\t\t| 编号 |       药品名     | 库存 | 单价 | 数量 |\n");
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
		printf("\t\t\t请确认药品数量!是否修改(Y/N)?");
		if(toupper(getche())=='Y')
		{
			printf("\n\t\t\t请输入产品编号："); 
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
				
				printf("\t\t\t%s的原数量为%d.",p->name,d[i-1]);
				printf("\t请输入修改值："); 
				scanf("%d",&d[i-1]);
				printf("\t\t\t%s的修改后数量为%d.",p->name,d[i-1]);
				if(d[i-1]==0)
				{  
					L=YMSC(L,num);
					for(j=i-1;j<icount;j++)
					{
						d[j]=d[j+1];
					}
				}
				printf("是否继续修改(Y/N)?");
				if(toupper(getche())=='Y')
				{
					printf("\n\t\t\t请输入产品编号：");
					scanf("%d",&num);
					c=1;
				}
				else c=0;
			}
		}
		printf("\n\t\t\t你购买的药品如下：\n");
		printf("\t\t\t------------------------------------------------\n"); 
		printf("\t\t\t|           ***购物车(共有%2d种药)***           |\n",icount);
		printf("\t\t\t------------------------------------------------\n");
		printf("\t\t\t| 编号 |       药品名     | 库存 | 单价 | 数量 |\n");
		printf("\t\t\t------------------------------------------------\n");
		t=L->next;
		if(t==NULL)
		{
			printf("\t\t\t购物车已无药品！");
			printf("\t\t\t是否重新选购(Y/N)?");
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
		printf("\t\t\t总计%d件药品，共%.1f元.\n",sum,m);
		printf("\t\t\t是否确认购买(Y/N)?");
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
			printf("\t\t\t\t购买完成！\n");
		}
		else
		{
			printf("\t\t\t\n放弃购买！\n");
		}
		L->next=NULL;
	}
	icount=0;
	printf("\n\t\t\t\t任意键退出！");
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
		printf("\t\t\t\t|********药品购买系统********|\n");
		printf("\t\t\t\t------------------------------\n");
		printf("\t\t\t\t|        1.选购药品          |\n");
		printf("\t\t\t\t|        2.购 物 车          |\n");
		printf("\t\t\t\t|        0.退出系统          |\n");
		printf("\t\t\t\t------------------------------\n");
		printf("\t\t\t\t请选择：");
		scanf("%d",&c);
		switch(c)
		{
			case 1: pHead=readfile();
					L=GM(pHead,L); break;
			case 2: L=GWC(pHead,L); break;
			case 0: exit(1); break; 
			default: printf("\t\t\t\t输入有误！请重新选择:"); break;
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
		printf("\t\t\t\t|********药店管理系统********|\n");
		printf("\t\t\t\t------------------------------\n");
		printf("\t\t\t\t|       1.登陆管理系统       |\n");
		printf("\t\t\t\t|       2.进入购买系统       |\n");
		printf("\t\t\t\t|       0. 退 出 系 统       |\n");
		printf("\t\t\t\t------------------------------\n");
		printf("\t\t\t\t\t请选择登陆：");
		scanf("%d",&c);
		switch(c)
		{
			case 1: GL(); break;
			case 2: YH(); break;
			case 0: printf("\t\t\t\t系统已退出！\n"); break; 
			default: printf("\t\t\t\t输入有误！请重新选择:"); break;
		}
	}while(c); 
}
