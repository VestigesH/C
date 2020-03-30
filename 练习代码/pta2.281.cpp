#include <stdio.h>
main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d + %d = %d \n", x, y, x + y);
    printf("%d - %d = %d \n", x, y, x - y);
    printf("%d * %d = %d \n", x, y, x * y);
    if(y != 0)
        printf("%d / %d = %d \n", x, y, x / y);
    else 
        return 0;
}
