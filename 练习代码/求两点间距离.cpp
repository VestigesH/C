#include <stdio.h>
#include <math.h>
#define N 3
int Num[N][2];
void Input()
{
	int i, j;
	printf("请输入点的坐标："); 
	for(i = 0; i < N; i++)
		scanf("%d %d",&Num[i][0], &Num[i][1]);
}
void GetDistance()
{
	int x1, x2, y1, y2, i, j, count = 0;
	double distance;
	for(i = 0; i< N; i++)
	{
		for(j = 0; j < 2; j++)
		{
			x1 = Num[i][0];
			y1 = Num[i][1];
			x2 = Num[i + 1][0];
			y2 = Num[i + 1][1];
			distance = sqrt(pow((x2 - x1) , 2) + pow((y2 - y1) , 2));
			if(count % N == 0)
				printf("\n");
			printf("%.2lf\t",distance);
		}
	}
}
int main()
{
	Input();
	GetDistance();
	return 0;
} 

