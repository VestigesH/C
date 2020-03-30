
#include <stdio.h>
int main()
{
    int m, n, i, j, nums[101], t;
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    m %= n;
    for(i = 0; i < m; i++)
    {
        t = nums[0];
        for(j = 0; j < n - 1; j++)
            nums[j] = nums[j+1];
        nums[n - 1] = t;
    }
    for(i = 0; i < n; i++)
    {
        if(i)
            printf(" ");
        printf("%d", nums[i]);
    }
}
