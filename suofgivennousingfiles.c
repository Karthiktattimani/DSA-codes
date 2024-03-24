#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    int s = 0;
    FILE *fp, *fp2;

    fp = fopen("read.txt", "r");
    fp2 = fopen("output.txt", "w");

    if (fp == NULL || fp2 == NULL) {
        printf("File not found\n");
        return 1; // Exit the program with error code 1
    }

    fscanf(fp, "%d", &n);

    if (n < 0) {
        fprintf(fp2, "sum=%d\n", n);
    } else {
        while (n != 0) {
            s = s + n % 10;
            n = n / 10;
        }
        fprintf(fp2, "sum = %d\n", s);
    }

    fclose(fp);
    fclose(fp2);
    return 0;
}
