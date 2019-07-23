#include <stdio.h>
int main()
{
	int choice;
	printf("\n		******自动贩卖机查询系统******\n");
	printf("查询价格请按商品前的序号,按0退出查询。\n");
	printf("				1.绿茶\n");
	printf("				2.可乐\n");
	printf("				3.芬达\n");
	printf("				4.矿泉水\n");
	printf("				5.爆米花\n");
	printf("				6.瓜子\n");
	printf("				0.退出\n");
	printf("您要查询: ");
	scanf("%d",&choice);
	switch (choice)
	{
		case 1:printf("绿茶：4元/瓶");break;
		case 2:printf("可乐：3.5元/瓶");break;
		case 3:printf("芬达：3元/瓶");break;
		case 4:printf("矿泉水：1.5元/瓶");break;
		case 5:printf("爆米花：5元/桶");break;
		case 6:printf("瓜子：2.5元/袋");break;
		case 0:return 0;
	}
	printf("\n"); 
}
