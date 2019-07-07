#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
int main()
{
	int *array=NULL,num,i;
	printf("please input the number of element:");
	scanf("%d",&num);
	array=(int*)malloc(sizeof(int)*num);
	if(array==NULL)
	{
		printf("out of memory ,press any key to quit...\n");
		exit(0);
	}
	printf("please input %d element: ",num);
	for(i=0;i<num;i++)
		scanf("%d",&array[i]);
	printf("%d elements are: \n",num);
	for(i=0;i<num;i++)
		printf("%d,",array[i]);
	free(array);
}
