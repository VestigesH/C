//给定一个链表，删除链表的倒数第 n 个节点，并且输出删除后的链表
#include <stdio.h> 
#include <stdlib.h>
int location;
struct Data
{
	int number;
	struct Data *next;	
};
void Create(struct Data *pHead)
{
	struct Data *p1, *p2;
	int n;
	pHead->next = NULL;
	p1 = pHead;
	printf("请输入链表(以0结束输入)：");
	scanf("%d", &n);
	while( n != 0)
	{
		p2 = (struct Data *)malloc(sizeof(struct Data));
		p2->number = n;
		p2->next = p1->next;
		p1>next  = p2;
		p1 = p2;
		scanf("%d", &n);
	}
}


