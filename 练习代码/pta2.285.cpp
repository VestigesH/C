#include <stdio.h>
main()
{
	int hight;
	scanf("%d",&hight);
	if(hight >= 100 && hight <= 300)
		printf("%.1f",((hight - 100) * 0.9 * 2));
	else
		return 0;
}
