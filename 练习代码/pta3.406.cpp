#include <stdio.h>
#include <math.h>
main()
{
	int N, W, H, i;
	scanf("%d",&N);
	if(N <= 20)
	{
		for(i = 0; i < N; i++)
		{
			scanf("%d %d",&H ,&W);
			if(H < 200 && H > 120 && W <= 300 && W > 50)
			{
				float S = (H - 100) * 0.9 * 2;
			    if(fabs(W - S) < (S * 0.1))
				{
					printf("You are wan mei!\n");
				}
				else if(fabs(W - S) >= (S * 0.1) && (W > S))
				{
					printf("You are tai pang le!\n");
				}
				else
				{
					printf("You are tai shou le!\n");
				}	
			}
		}
	}
	return 0;
}
