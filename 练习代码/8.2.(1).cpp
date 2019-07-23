#include <stdio.h>
struct data
{
	int num;
	float score;
};
struct data fn(struct data d)
{
	d.num+=23;
	d.score=99.9;
	return d;
}
int main()
{
	struct data d0,d1={101,88.8};
	d0=fn(d1);
	printf("%d %f\n %d %f\n",d0.num,d0.score,d1.num,d1.score);
}
