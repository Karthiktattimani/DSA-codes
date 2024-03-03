#include<stdio.h>

int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9};
    int *p;
    p=&a;
    printf("%d",a);
    printf("\n");
    printf("%d",*a);
    printf("\n");
    printf("%d",*(a+1));
    printf("\n");
}
