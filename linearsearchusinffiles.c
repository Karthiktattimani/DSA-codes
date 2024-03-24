#include <stdio.h>
#include <stdio.h>
#include <string.h>
int main() {
    FILE *fp, *fp2;
    fp = fopen("read.txt", "r");
    fp2 = fopen("output.txt", "w");
    int n, x, c = 0;
    int a[100];
    if (fp == NULL || fp2 == NULL) {
        printf("File not found\n");
        return 1;
    }
    fscanf(fp, "%d", &x);
    fscanf(fp, "%d", &n);
    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &a[i]);
        printf("%d ", a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            c++;
            fprintf(fp2, "found at position = %d\n", i + 1);
        }
    }
    if (c == 0) {
        fprintf(fp2, "not found\n");
    }
    fclose(fp);
    fclose(fp2);
    return 0;
}
