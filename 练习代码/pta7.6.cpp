#include <stdio.h>
main()
{
	int N, i, s = 0, t;
	scanf("%d",&N);
	if(N < 1000000000)
	{
		while(N>0)
		{
			t = N % 10;
			N /= 10;
			s += t;
			i++;
		}
		printf("%d %d",i,s);
	}
	else
		return 0;
}
