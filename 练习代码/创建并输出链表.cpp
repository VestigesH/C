#include <stdio.h>
#include <stdlib.h>
struct student
{
	char cName[20];
	int iNumber;
	struct student *next;
};
int icount;
struct student *Create()
{
	struct student *pHead = NULL;
	struct student *pEnd, *pNew;
	icount = 0;
	pEnd = pNew = (struct student *)malloc (sizeof (struct student));
	printf("������ѧ����������ѧ�ţ�");
	scanf("%s", pNew->cName);
	scanf("%d", pNew->iNumber);
	while(pNew->iNumber != 0){
		icount ++;
	if(icount == 1){
		pNew->next = pHead;
		pEnd = pNew;
		pHead = pNew;
	} 
	else
	{
		pNew->next = NULL;
		pEnd->next = pNew;
		pEnd = pNew;
	}
	pNew = (struct student *)malloc (sizeof (struct student));
	scanf("%s", pNew->cName);
	scanf("%d", pNew->iNumber);
	}
	free(pNew);
	return pHead;
}
void print(struct student *pHead)
{
	struct student *pTemp;
	int iIndex = 1;
	printf("****************����������%d��ѧ����************************\n",icount);
	pTemp = pHead;
	while(pTemp != NULL)
	{
		printf("��%d��ѧ���ǣ�\n", iIndex);
		printf("������\n", pTemp->cName);
		printf("ѧ�ţ�\n", pTemp->iNumber);
		pTemp = pTemp->next;
		iIndex++; 
	} 
}
int main()
{
	struct student *pHead;
	pHead = Create();
	print(pHead);
} 
