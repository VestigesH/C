#include <stdio.h>
void Printn(int N)
{
	int i;
	for(i = 1; i <= N; i++)
		printf("%d\n",i);
}
main()
{
	int N;
	scanf("%d",&N);
	Printn(N);
	return 0;
} 
