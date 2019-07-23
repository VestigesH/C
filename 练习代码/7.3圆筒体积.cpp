#include <stdio.h>
#include <math.h>
#define PI 3.14
float Volume(float r, float wr, float h)
{
	float volume;
	volume = ((wr * wr - r * r) * PI) * h;
	return volume;
}
int main()
{
	printf("%f",PI);
	float r, wr, h;
	float volume;
	printf("请输入圆筒的半径，外径和高：");
	scanf("%f %f %f",&r, &wr, &h);
	volume = Volume(r, wr, h);
	printf("圆筒的体积为：%.4f",volume);
}
