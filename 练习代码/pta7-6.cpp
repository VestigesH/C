#include <stdio.h>
main()
{
	int n, x, y, z, account;
	scanf("%d",&n);
	account = 0;
	for(x = 1; x < 20; x++)
	{
		for(y = 1; y < 33; y++)
		{
			
			for(z = 1; z < 100; z++)
			{
				
				if((5 * x + 3 * y + 1 * z == 100) && (x + y + 3 * z == 100))
				{
					account++;
					if(account <= n)
						printf("%d %d %d\n",x ,y ,3 * z);	
					else
						break;
				}
			} 
		} 
	}		
}
