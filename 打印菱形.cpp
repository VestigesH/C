#include "stdio.h"
int main(){
	int i,j;
	//��ʼ��һ����
	for(i = 1; i <= 3; i++){

		//�����һ���ֿո�
		for(j = 1; j <= (4 - i); j++){
			printf(" ");
		}

		//�����һ�����Ǻ�
		for(j = 1;j <= (-1 + 2 * i); j++){
			printf("*");
		}
		printf("\n");
	 
	}

	//��ʼ�ڶ�����
	for(i = 1; i <= 2; i++){

		//����ڶ����ֿո�
		for(j = 1;j <= ( 2 + i - 1 );j++){
			printf(" ");
		}

		//����ڶ������Ǻ�
		for(j = 1;j <= ( 5 - 2 * i );j++){
			printf("*");
		}
		printf("\n");

	}
return 0;
}
