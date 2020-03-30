#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{
	double sum = 0, eps = 0, num =0;
	int i = 1, k = 1;
	scanf("%lf", &eps);
	do
	{
		num = k * 1.0 / i;
		sum += num;
		i += 3;
		k = -k;
	} while (fabs(num) > eps);
	printf("sum = %.6f\n", sum);
	return 0;
}

