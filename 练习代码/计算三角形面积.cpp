#include <stdio.h>
#include <math.h>
main()
{
	double a, b, c;
	double s , area;
	printf("������a,b,c:");
	scanf("%lf%lf%lf", &a, &b, &c);
	if(a + b > c || b + c > a || a + c > b)
	{
		s = ( a + b + c) / 2;
		area = sqrt(s * (s - a) * (s - b) * (s - c));
		printf("���Ϊ��%lf",area);
	}
	else
		printf("�������߲������һ��������");
}
