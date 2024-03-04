#include <stdio.h>

void readmatrix(int n);
void readmatrix2(int n);
void multiply(int mat1[10][10], int mat2[10][10], int n);
void printmatrix(int n, int a[10][10]);
int findRank(int n, int a[10][10]);

int mat1[10][10], mat2[10][10];
int a[10][10];

int main() {
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

    int rank = findRank(n, a);
    printf("The rank of the multiplied matrix is: %d\n", rank);

    return 0;
}

void readmatrix(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
}

void readmatrix2(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
}

void multiply(int mat1[10][10], int mat2[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = mat1[i][j] * mat2[i][j];
        }
    }
}

void printmatrix(int n, int a[10][10]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int findRank(int n, int a[10][10]) {
    int rank = n;

    for (int row = 0; row < rank; row++) {
        // Diagonal element is non-zero
        if (a[row][row] != 0) {
            for (int col = 0; col < n; col++) {
                if (col != row) {
                    // Make the non-diagonal elements in this column zero
                    double multiplier = (double)a[col][row] / a[row][row];
                    for (int i = 0; i < rank; i++) {
                        a[col][i] -= multiplier * a[row][i];
                    }
                }
            }
        } else {
            // Diagonal element is zero, so swap with a non-zero row below it
            int reduce = 1;
            for (int i = row + 1; i < n; i++) {
                if (a[i][row] != 0) {
                    for (int j = 0; j < rank; j++) {
                        int temp = a[row][j];
                        a[row][j] = a[i][j];
                        a[i][j] = temp;
                    }
                    reduce = 0;
                    break;
                }
            }
            if (reduce) {
                // All elements in this column are zero, reduce rank
                rank--;
                for (int i = 0; i < n; i++) {
                    a[i][row] = a[i][rank];
                }
            }
            row--;
        }
    }

    return rank;
}

