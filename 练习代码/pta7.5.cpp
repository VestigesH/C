#include <stdio.h>
main()
{
    int x1, x2;
    int sum =0;
    char ch;
    scanf("%d",&x1);
    while((ch = getchar()) != '=')
    {
        scanf("%d",&x2);
        if(ch =='/' && x2 == 0)
		{
            printf("ERROR\n");
            return 0;
 
        }
        switch(ch)
        {
            case '+':
				sum = x1 + x2;
				break;
            case '-':
				sum = x1 - x2;
				break;
            case '*':
				sum = x1 * x2;
				break;
            case '/':
				sum = x1 / x2;
				break;
            default:
				printf("ERROR\n");
				return 0;
 
        }
        x1 = sum;
    }
    printf("%d\n",x1);
    return 0;
}
