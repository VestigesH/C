//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
#include <stdio.h>
#include <stdlib.h>
struct Data
{
	int number;
	struct Data *next;
};
void Create(struct Data *pHead)   
{
	struct Data *pNew, *pMove;
	int n;
	pHead->next = NULL;
	pNew = pHead;
	printf("请输入排好序的链表(从小到大,以0结束输入)：");
	scanf("%d", &n);
	while( n != 0)
	{
		pMove = (struct Data *)malloc(sizeof(struct Data));
		pMove->number = n;
		pMove->next = pNew->next;
		pNew->next  = pMove;
		pNew = pMove;
		scanf("%d", &n);
	}
}
void output(struct Data *pHead)
{
	struct Data *p = (struct Data *)malloc(sizeof (struct Data));
	p = pHead->next;
	while(p != NULL)
	{
		printf("%3d",p->number);
		p = p->next;
	}
} 
struct Data *Delete(struct Data *pHead)
{
	struct Data *q = (struct Data *)malloc(sizeof(struct Data));
	q = pHead->next;
	while(q->next && q)
	{
		if(q->number == q->next->number)
			q->next = q->next->next;//删除重复元素
		q = q->next; 
		if(!q)
			break;
	}
	return pHead;
}
int main()
{
	struct Data *pHead = (struct Data *)malloc(sizeof(struct Data));
	Create(pHead);  
	Delete(pHead);
	printf("不重复链表为：");
	output(pHead);
}
