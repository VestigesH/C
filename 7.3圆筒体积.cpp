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
	printf("������ԲͲ�İ뾶���⾶�͸ߣ�");
	scanf("%f %f %f",&r, &wr, &h);
	volume = Volume(r, wr, h);
	printf("ԲͲ�����Ϊ��%.4f",volume);
}
