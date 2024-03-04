#include<stdio.h>

void readmatrix(int n);
void readmatrix2(int n);
void multiply(int mat1[10][10], int mat2[10][10], int n);
void printmatrix(int n, int a[10][10]);
int mat1[10][10], mat2[10][10];
int a[10][10];



int main()
{
    int n;

    printf("Enter the size of matrix\n");
    scanf("%d", &n);

    printf("Enter the first matrix:\n");
    readmatrix(n);

    printf("Enter the second matrix:\n");
    readmatrix2(n);

    multiply(mat1, mat2, n);
    printf("The matrix after multiplication:\n");
    printmatrix(n, a);

    return 0;
}

void readmatrix(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
         {
            scanf("%d", &mat1[i][j]);
         }
    }
}

void readmatrix2(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }
}

void multiply(int mat1[10][10], int mat2[10][10], int n)
 {
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            a[i][j] = mat1[i][j] * mat2[i][j];
        }
    }
}

void printmatrix(int n, int a[10][10])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}







