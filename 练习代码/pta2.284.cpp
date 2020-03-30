#include <stdio.h>
main()
{
	int D; 
	scanf("%d",&D); 
	if(D >= 1 && D <= 7)
		printf("%d",(D + 2) % 7 == 0 ? 7 :( D + 2) % 7);
	else
		return 0;
}
