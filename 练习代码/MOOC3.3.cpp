#include <stdio.h>
#include <math.h>
main()
{
	float x1, y1, x2, y2, D;
	scanf("%f,%f",&x1, &y1);
	scanf("%f,%f",&x2, &y2);
	D = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	printf("D=%.2f",D);
}
