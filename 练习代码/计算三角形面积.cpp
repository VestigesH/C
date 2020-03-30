#include <stdio.h>
#include <math.h>
main()
{
	double a, b, c;
	double s , area;
	printf("请输入a,b,c:");
	scanf("%lf%lf%lf", &a, &b, &c);
	if(a + b > c || b + c > a || a + c > b)
	{
		s = ( a + b + c) / 2;
		area = sqrt(s * (s - a) * (s - b) * (s - c));
		printf("面积为：%lf",area);
	}
	else
		printf("此三条边不能组成一个三角形");
}
