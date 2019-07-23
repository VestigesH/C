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
	printf("请输入学生的姓名和学号：");
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
	printf("****************本名单共有%d个学生：************************\n",icount);
	pTemp = pHead;
	while(pTemp != NULL)
	{
		printf("第%d个学生是：\n", iIndex);
		printf("姓名：\n", pTemp->cName);
		printf("学号：\n", pTemp->iNumber);
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
