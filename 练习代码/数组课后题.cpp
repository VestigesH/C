#include <stdio.h>
#include <string.h>
main()
{
	int i, j, t, Nums[10] = {32,43,11,44,212,34,32,10,22,12};
//	for(i = 0; i < 9; i++)           Ã°ÅİÅÅĞò 
//	{
//		for(j = 0; j < 9 - i; j++)
//		{
//			if(Nums[j] > Nums[j+1])
//			{
//				t = Nums[j];
//				Nums[j] = Nums[j + 1];
//				Nums[j + 1] = t;
//			}	
//		}
//	} 
 	for(i = 0; i < 9; i++)                    //Ñ¡ÔñÅÅĞò 
 	{
 		for(j = i + 1; j <= 9; j++)
 		{
 			if(Nums[i] > Nums[j])
 			{
 				t = Nums[i];
				Nums[i] = Nums[j];
				Nums[j] = t; 
		 	} 	  
		 }
	 }
	for(i = 0; i < 10; i++)
		printf("%5d",Nums[i]);
} 
