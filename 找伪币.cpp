#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int a = 0,b = 0,c = 0;
int count = 0;
int weight1 =0,weight2=0,weight3=0;
void Findfalse(int Coin[], int m);
void Devide(int m, int n,int Coin[])
{
	int i;
	weight1=weight2=weight3=0;
	printf("分堆情况为：");
	if(n%3==0)
	{
		a=n/3;
		b=n/3;
		c=n/3;
	}
	else if(n%3==1)
	{
		a=n/3;
		b=n/3;
		c=n/3+1;
	}
	else 
	{
		a=n/3+1;
		b=n/3+1;
		c=n/3;
	}
	printf("%d %d %d\n",a,b,c);
	for(i=m;i<m+a;i++)
	{
		weight1+=Coin[i];
	}
	for(;i<m+a+b;i++)
	{
		weight2+=Coin[i];
	}
	for(;i<m+a+b+c;i++)
	{
		weight3+=Coin[i];
	}
	printf("硬币的重量：");
	printf("%d %d %d\n",weight1,weight2,weight3);
	count++;
	Findfalse(Coin, m);
}
void Findfalse(int Coin[], int m)
{
	printf("\n第%d次比较：\n",count); 
	while(1)
	{
		if(a==b)
		{
			if(weight1==weight2)
			{
				if(c==1)
				{
					printf("第%d个为伪币",m+a+b+c);
					break;
				}
				if(c==2)
				{
					if(Coin[m+a+b+c-2]>Coin[m+a+b+c-1])
					{
						printf("第%d个为伪币",m+a+b+c);
						break;
					}
					if(Coin[m+a+b+c-2]<Coin[m+a+b+c-1])
					{
						printf("第%d个为伪币",m+a+b+c-1);
						break;
					}
				}
				if(c>2) 
				{
					Devide(m+a+b, c,Coin);
					break;
				}
			}
			else if(weight1>weight2)
			{
				if(b==2)
				{
					if(Coin[m+a+b-2]>Coin[m+a+b-1])
					{
						printf("第%d个为伪币",m+a+b);
						break;
					}
					if(Coin[m+a+b-2]<Coin[m+a+b-1])
					{
						printf("第%d个为伪币",m+a+b-1);
						break;
					}
				}
				if(b==1)
				{
					printf("第%d个为伪币",m+a+b);
				}
				if(b>2)
				{
					Devide(m+a, b,Coin);
					break;
				}
			}
			else
			{
				if(a==2)
				{
					if(Coin[m+a-2]>Coin[m+a-1])
					{
						printf("第%d个为伪币",a+m);
						break;
					}
					if(Coin[m+a-2]<Coin[m+a-1])
					{
						printf("第%d个为伪币",m+a-1);
						break;
					}
				}
				if(a==1)
				{
					printf("第%d个为伪币",m+a);
				}
				if(a>2)
				{
					Devide(0+m, a,Coin);
					break;
				}	
			}
		}
		if(a==c)
		{
			if(weight1==weight3)
			{
				if(b==1)
				{
					printf("第%d个为伪币",a+b+m);
					break;
				}
				if(b==2)
				{
					if(Coin[m+a+b-2]>Coin[m+a+b-1])
					{
						printf("第%d个为伪币",m+a+b);
						break;
					}
					if(Coin[m+a+b-2]<Coin[m+a+b-1])
					{
						printf("第%d个为伪币",m+a+b-1);
						break;
					}
				}
				if(b>2) 
				{
					Devide(a+m, b,Coin);
					break;
				}
			}
			else if(weight1>weight3)
			{
				if(c==2)
				{
					if(Coin[m+a+b+c-2]>Coin[m+a+b+c-1])
					{
						printf("第%d个为伪币",m+a+b+c);
						break;
					}
					if(Coin[m+a+b+c-2]<Coin[m+a+b+c-1])
					{
						printf("第%d个为伪币",m+a+b+c-1);
						break;
					}
				}
				if(c==1)
				{
					printf("第%d个为伪币",m+a+b+c);
					break;
				}
				if(c>2)
				{
					Devide(a+b+m, c,Coin);
					break;
				}
			}
			else
			{
				if(a==2)
				{
					if(Coin[m+a-2]>Coin[m+a-1])
					{
						printf("第%d个为伪币",a+m);
						break;
					}
					if(Coin[m+a-2]<Coin[m+a-1])
					{
						printf("第%d个为伪币",m+a-1);
						break;
					}
				}
				if(a==1)
				{
					printf("第%d个为伪币",a+m);
				}
				if(a>2)
				{
					Devide(0+m, a,Coin);
					break;
				}
			}
		}
		if(b==c)
		{
			if(weight2==weight3)
			{
				if(a==1)
				{
					printf("第%d个为伪币",a+m);
					break;
				}
				if(a==2)
				{
					if(Coin[m+a-2]>Coin[m+a-1])
					{
						printf("第%d个为伪币",a+m);
						break;
					}
					if(Coin[m+a-2]<Coin[m+a-1])
					{
						printf("第%d个为伪币",m+a-1);
						break;
					}
				}
				if(a>2) 
				{
					Devide(0+m, a,Coin);
					break;
				}
			}
			else if(weight2>weight3)
			{
				if(c==2)
				{
					if(Coin[m+a+b+c-2]>Coin[m+a+b+c-1])
					{
						printf("第%d个为伪币",m+a+b+c);
						break;
					}
					if(Coin[m+a+b+c-2]<Coin[m+a+b+c-1])
					{
						printf("第%d个为伪币",m+a+b+c-1);
						break;
					}
				}
				if(c==1)
				{
					printf("第%d个为伪币",m+a+b+c);
				}
				if(c>2)
				{
					Devide(m+a+b, c,Coin);
					break;
				}
			}
			else
			{
				if(b==2)
				{
					if(Coin[m+a+b-2]>Coin[m+a+b-1])
					{
						printf("第%d个为伪币",m+a+b);
						break;
					}
					if(Coin[m+a+b-2]<Coin[m+a+b-1])
					{
						printf("第%d个为伪币",m+a+b-1);
						break;
					}
				}
				if(b==1)
				{
					printf("第%d个为伪币",m+a+b);
				}
				if(b>2)
				{
					Devide(m+a, b,Coin);
					break;
				}
			}
		}	
	}
}
int main()
{
	int i,n;
	int falsecoin;
	int Coin[100];
	printf("请输入硬币的总个数：");
	scanf("%d",&n);
	srand((unsigned)time(NULL));
	falsecoin = rand() % n;
	printf("%d\n", falsecoin+1);
	for(i = 0; i < n; i++)
		Coin[i] = 1;   	
	Coin[falsecoin] = 0;
	for(i = 0; i < n; i++)
	{
		printf("%d",Coin[i]);
	}	
	printf("\n");
	Devide(0, n,Coin);
}



