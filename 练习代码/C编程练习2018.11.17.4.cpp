#include <stdio.h>
#include <inttypes.h>
int main(void)
{
	int32_t me32;
	
	me32 =45933945;
	printf("First,assume int32_t is int:");
	printf("me 32=%d\n",me32);
	printf("Next,Let's not make any assimptions.\n");
	printf("Instead,use a \"macro\"from inttypes.h");
	printf("me32 = %"  " d"  " \n",me32);
	return 0;
	
}
