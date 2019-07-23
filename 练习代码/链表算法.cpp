#include <stdio.h>
#include <stdlib.h>
struct Data *p1,*p2,*tmp;
 
struct Data
{
	int number;
	struct Data *next;
};
void Insert(struct Data *d1, struct Data *d2) 
{ 
    p1 = d1;
    p2 = d2->next;
    while(p1->next && p2)
    {
        if(p1->next->number > p2->number)
        {
            tmp = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p2 = tmp;
        }
        else
            p1 = p1->next;
    }
    if(p2)
        p1->next = p2;
}
Data *print(struct Data *pHead) 
{ 
	struct Data *pTemp;
	pTemp = pHead;
    while(pTemp != NULL) 
    { 
        printf(" %d ",pHead->next->number); 
        pTemp = pTemp->next; 
    } 
    printf("%d",pHead->number);
    return p1;
}
int main() 
{ 
    int n1, n2, i; 
    Data *pHead1, *pHead2; 
	Data *ph1, *ph2; 
	Data *t1, *t2;
	p1 = (struct Data*)malloc(sizeof(struct Data)); 
	p2 = (struct Data*)malloc(sizeof(struct Data));
    pHead1 = (struct Data*)malloc(sizeof(struct Data)); 
    pHead2 = (struct Data*)malloc(sizeof(struct Data)); 
    pHead1->next = NULL; 
    pHead2->next = NULL; 
	ph1 = pHead1;
	ph2 = pHead2;
    printf("请输入第一个链表的节点数：");
	scanf("%d", &n1); 
	printf("请输入第一个链表中的数据：");
	for(i = 0; i < n1; i++)
	{
		t1 = (struct Data*)malloc(sizeof(struct Data)); 
		scanf("%d",&t1->number);
		p1->number = t1->number;
		t1->next = p1;  
		ph1 = t1;
	}
	print(pHead1);
	printf("请输入第二个链表的节点数：");
	scanf("%d", &n2); 
	printf("请输入第二个链表中的数据：");
	for(i = 0; i < n2; i++)
	{
		t2 = (struct Data*)malloc(sizeof(struct Data)); 
		scanf("%d",&t2->number);
		p2->number = t2->number;
		t2->next = NULL;
		p2 = t2;
	}
    Insert(pHead1,pHead2); 
    print(p1);
} 

    
