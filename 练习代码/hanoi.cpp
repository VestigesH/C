#include <stdio.h>
void hanoi(int n, char x, char y, char z)
{
	if(n == 1)
		printf("%c -> %c\n",x,z);
	else
		{
			hanoi(n - 1,x, z, y);
			printf("%c -> %c\n",x,z);
			hanoi(n - 1, y, x, z);
		}
}
main()
{
	int m;
	printf("input the number of disks:");
	scanf("%d",&m);
	printf("The steps to moving %3d disks:\n",m);
	hanoi(m, 'A', 'B', 'C');
}
