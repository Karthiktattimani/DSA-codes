#include <stdio.h>

int ispalindrome(int n)
{
    int rem, temp, rev = 0;
    temp = n;
    while (n != 0)
    {
        rem = n % 10;
        rev = rev * 10 + rem;
        n = n / 10;
    }
    if (rev == temp)
        return 1;
    else
        return 0;
}

int main()
{
    int n, d;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    d = ispalindrome(n);
    if (d == 1)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");
    return 0;
}
