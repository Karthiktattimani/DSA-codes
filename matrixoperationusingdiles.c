#include <stdio.h>

void readM(FILE *fp, int m[][100], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            fscanf(fp, "%d", &m[i][j]);
        }
    }
}

void print(FILE *fp, int m[][100], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            fprintf(fp, "%d ", m[i][j]);
        }
        fprintf(fp, "\n");
    }
}

void addM(int m1[][100], int m2[][100], int res[][100], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void subM(int m1[][100], int m2[][100], int res[][100], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = m1[i][j] - m2[i][j];
        }
    }
}

void mulM(int mat1[][100], int mat2[][100], int res[][100], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transpose(int m[][100], int tr[][100], int r, int c) {
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            tr[i][j] = m[j][i];
        }
    }
}

int main() {
    FILE *fp, *fp2;
    fp = fopen("read.txt", "r");
    fp2 = fopen("output.txt", "w");

    if (fp == NULL || fp2 == NULL) {
        printf("File not found\n");
        return 1;
    }

    int r1, c1, r2, c2;
    fscanf(fp, "%d %d", &r1, &c1);
    fscanf(fp, "%d %d", &r2, &c2);

    if (r1 != r2 || c1 != c2) {
        printf("Matrix operations require matrices of the same dimensions.\n");
        fclose(fp);
        fclose(fp2);
        return 1;
    }

    int m1[100][100], m2[100][100], res[100][100], tr[100][100];

    readM(fp, m1, r1, c1);
    readM(fp, m2, r2, c2);


    addM(m1, m2, res, r1, c1);
    fprintf(fp2, "Matrix Addition Result:\n");
    print(fp2, res, r1, c1);


    subM(m1, m2, res, r1, c1);
    fprintf(fp2, "\nMatrix Subtraction Result:\n");
    print(fp2, res, r1, c1);


    mulM(m1, m2, res, r1, c1, c2);
    fprintf(fp2, "\nMatrix Multiplication Result:\n");
    print(fp2, res, r1, c2);


    transpose(m1, tr, r1, c1);
    fprintf(fp2, "\nTranspose of Matrix 1:\n");
    print(fp2, tr, c1, r1);

    fclose(fp);
    fclose(fp2);

    return 0;
}
