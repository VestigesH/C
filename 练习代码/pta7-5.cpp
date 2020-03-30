#include <stdio.h>
main()
{
	int N, s1, s2 ,i;
	scanf("%d",&N);
	getchar();
	while(N--)
	{
		s1 = 0;
		s2 = 0;
		for(i = 1; i <= 3; i++)
		{
			char a;
			scanf("%c",&a);
			s1 += a;
		}
		for(i = 1; i <= 3; i++)
		{
			char a;
			scanf("%c",&a);
			s2 += a;
		}
		if(s1 == s2)
			printf("You are lucky!\n");
		else 
			printf("Wish you good luck.\n");
		getchar();
	}
	return 0;
}
