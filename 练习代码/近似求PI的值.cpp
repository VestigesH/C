#include <math.h>
#include <stdio.h> 
main()
{
	int s = 1;
	float t, n, pi;
	t = 1;
	n = 1.0;
	pi = 0;
	while(fabs(t) >= 1e-6)
	{
		pi += t;
		n += 2;
		s = -s;
		t = s / n;
	}
	pi *= 4;
	printf("pi=%f",pi);
}
