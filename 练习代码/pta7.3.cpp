#include <stdio.h>
main()
{
	int N, sum = 0, rest = 1;
	scanf("%d",&N);
	while(N > 1 && N <= 10)
	{
		sum = (rest + 1) * 2; 
		rest = sum;
		N--;
	}
	printf("%d",sum);	
}
