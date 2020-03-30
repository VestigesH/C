#include <stdio.h>
main()
{
	int time, h, m;
	scanf("%d",&time);
	h = time / 60;
	m = time - (h * 60);
	if(m < 10)
		printf("%d(m)=%d(h):0%d(m)",time,h,m);
	else
		printf("%d(m)=%d(h):%d(m)",time,h,m);
}
