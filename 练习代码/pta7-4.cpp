#include<stdio.h>
#include<string.h>
main()
{
	int a[1024][2], i, n, j, h, m, t, N;
	char A;
	scanf("%d",&N);
	for(i = 0; i < N; i++)
	{
		t = 0;
		n = 0;
		for(j = 0; j < 1024; j++)
		{
			a[j][0] = 0;
			a[j][1] = 0;
		}
		scanf("%d %c %d:%d",&j,&A,&h,&m);
		while(j)
		{
			if(A =='S')
			{
				a[j][0] = 1;
				a[j][1] = h * 60 + m;
			}
			else if(A =='E'&& a[j][0] == 1)
			{
				t += h * 60 + m - a[j][1];
				a[j][0] = 0;
				n++;
			}
			scanf("%d %c %d:%d",&j,&A,&h,&m);
		}
		if(n!=0)
			printf("%d %.0lf\n",n ,(double)t / n);
		else
			printf("0 %d\n",t);
	}
	return 0;
}

