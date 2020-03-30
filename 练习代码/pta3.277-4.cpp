#include <stdio.h>
main()
{
	int N, K, nums[100], i, j, t;
	scanf("%d %d",&N, &K);
	for(i = 0; i < N; i++)
		scanf("%d",&nums[i]);
	for(i = 0; i < K; i++)
	{
		for(j = 0; j < N - 1; j++)
		{
			if(nums[j] > nums[j + 1])
			{
				t = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = t;
			}
		}
	}
	for(j = 0; j < N - 1; j++)
	{
		printf("%d",nums[j]);
		printf(" ");
	}
	printf("%d",nums[N-1]);
	return 0;
}

