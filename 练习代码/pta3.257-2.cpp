#include<stdio.h>
int main()
{    
	int a[21], b[21], c[21];    
	int n, m, i, j;    
	int temp=0, num=0;
	scanf("%d",&n);    
	for(i = 0; i < n; i++)
		scanf("%d",&a[i]);        
	scanf("%d",&m);    
	for(i = 0; i < m; i++)
		scanf("%d",&b[i]);      
	for(i = 0; i < n; i++)
	{        
		for(j = 0; j <  m; j++)   
		{
			if(a[i] == b[j])
				break;  
		}         	      
		if(j == m)
		{            
			c[num] = a[i];            
			num++;        
		}    
	}	        	
	for(i = 0; i < m; i++)
	{        
		for(j = 0; j < n; j++) 
		{		           
			if(b[i] == a[j]) 
				break;
		}      
		if(j == n)
		{            
			c[num] = b[i];            
			num++;        
		}    
	}       
	for(i = 0;i < num; i++){        
		for(j = 0;j < i; j++)
		{
			if(c[i] == c[j])
				break;
		}            	        
		if(j == i)
		{            
			if(temp != 0)
				printf(" ");            	
			printf("%d",c[i]);            
			temp++;        
		}       
	}    
	return 0;   
}
