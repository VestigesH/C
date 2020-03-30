#include <stdio.h>
main()
{
	int N, i, j, X, nums[11];
	scanf("%d",&N);
	for(i = 0; i < N; i++)
		scanf("%d",&nums[i]);
	scanf("%d",&X);
	i = 0;
	while(nums[i] < X && i < N)
        i++;
	for(j = N - 1; j >= i; j--)
		nums[j + 1] = nums[j];
	nums[i] = X;
	for(i = 0; i < N + 1; i++)
		printf("%d ",nums[i]);
} 

