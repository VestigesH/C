#include "stdio.h"
int main(){
	int i,j;
	//开始第一部分
	for(i = 1; i <= 3; i++){

		//输出第一部分空格
		for(j = 1; j <= (4 - i); j++){
			printf(" ");
		}

		//输出第一部分星号
		for(j = 1;j <= (-1 + 2 * i); j++){
			printf("*");
		}
		printf("\n");
	 
	}

	//开始第二部分
	for(i = 1; i <= 2; i++){

		//输出第二部分空格
		for(j = 1;j <= ( 2 + i - 1 );j++){
			printf(" ");
		}

		//输出第二部分星号
		for(j = 1;j <= ( 5 - 2 * i );j++){
			printf("*");
		}
		printf("\n");

	}
return 0;
}
