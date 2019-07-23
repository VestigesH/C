#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Coins[100];
int Weight(int Start,int End)
{
	int weight = 0, i;
	for(i = Start;i <= End;i++)
		weight += Coins[i];
	return weight;
}
int Compare(int lStart, int lEnd, int rStart, int rEnd)
{
	int falseCoin;
//	printf("\nlStart = %d \t lEnd = %d \t rStart = %d \t rEnd = %d \n",lStart, lEnd, rStart, rEnd);
//	printf("\nlweight = %d \t rweight = %d\n",Weight(lStart, lEnd), Weight(rStart,rEnd));
	if(lStart == lEnd || rStart == rEnd){  //硬币只剩两或三枚的情况 
		if (Weight(lStart, lEnd) > Weight(rStart, rEnd)){
			if(Weight(lStart, lEnd) == 0) { 
				Compare(rStart, (rStart + rEnd) / 2, (rStart + rEnd) / 2 + 1, rEnd);
			}
			else
			{ 
				falseCoin = rStart;	
			} 
		}
		else
		{ 
			if(Weight(rStart, rEnd) == 0)
			{ 
				Compare(lStart, (lStart + lEnd) /2, (lStart + lEnd) / 2 + 1,lEnd);
			} 
			else
			{ 
				falseCoin = rStart; 	
			} 
		}
		printf("\n伪币在%d处！",falseCoin);
	}else{//硬币总数大于2 ，先判断重量 
		if(Weight(lStart, lEnd) < Weight(rStart, rEnd)){//伪币在左 
			Compare(lStart, (lStart + lEnd) / 2, (lStart + lEnd) / 2 +1,lEnd);
		}else if(Weight(lStart, lEnd) > Weight(rStart, rEnd)){//伪币在右 
			Compare(rStart, (rStart + rEnd) / 2, (rStart + rEnd) / 2 +1,rEnd);
		}else{//重量相等时，根据硬币个数多少判断伪币位置 
			if((lEnd - lStart) > (rEnd - rStart))//左边硬币数多 ，伪币在左 
				Compare(lStart, (lStart + lEnd) / 2, (lStart + lEnd) / 2 +1,lEnd);
			else//伪币在右 
				Compare(rStart, (rStart + rEnd) / 2, (rStart + rEnd) / 2 +1,rEnd);
		}	
	}
}
int main()
{
	int n , i , falseCoin;
	
	for(n = 4; n < 100; n ++) {
		printf("硬币数量：%d\n", n);
		for(falseCoin = 1; falseCoin < n; falseCoin ++) {
			for(i = 0;i < n; i++)
				Coins[i] = 1; 
			Coins[falseCoin] = 0;
			for( i = 0;i < n;i++)
				printf("%d",Coins[i]);
			printf("\n%d",falseCoin);
			Compare(0, n / 2 - 1, n / 2 + 1, n - 1);
		}
	} 
	
	
//	printf("请输入硬币数量：");
//	scanf("%d", &n);
//	srand(( unsigned ) time ( NULL ));
//	falseCoin = rand() % n;
//	for(i = 0;i < n; i++)
//		Coins[i] = 1; 
//	Coins[falseCoin] = 0;
//	for( i = 0;i < n;i++)
//		printf("%d",Coins[i]);
//	printf("\n%d",falseCoin);
//	Compare(0, n / 2 - 1, n / 2 + 1, n - 1);
} 
