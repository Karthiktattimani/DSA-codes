#include <stdio.h>

int main()
{
    int i, n, sum=0;
    printf("Enter limit: ");
    scanf("%d", &n);
    for(i=0; i<=n; i++)
    {
        if(i%2==0)
        {
            sum=sum+i;
        }
    }

    printf("Sum of odd numbers = %d", sum);

    return 0;
}

