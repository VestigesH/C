//����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�
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
	printf("�������ź��������(��С����,��0��������)��");
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
			q->next = q->next->next;//ɾ���ظ�Ԫ��
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
	printf("���ظ�����Ϊ��");
	output(pHead);
}
