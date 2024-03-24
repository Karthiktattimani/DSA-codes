#include <stdio.h>

int main() {
    FILE *fp, *fp2;
    int flag = 0;
    fp = fopen("read.txt", "r");
    fp2 = fopen("output.txt", "w");
    int n;
    if (fp == NULL || fp2 == NULL) {
        printf("File not found\n");
        return 1;
    }
    fscanf(fp, "%d", &n);
    printf("%d ",n);

    int a[100];
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &a[i]);
    }

    int key;
    fscanf(fp,"%d",&key);
    printf("%d ",key);

    int left = 0;
    int right = n - 1;

    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] == key) {
            result = mid;
            break;
        }

        if (a[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    if (result != -1)
        fprintf(fp2, "Element %d found at index %d\n", key, result);
    else
        fprintf(fp2, "Element %d not found in the array\n", key);

    fclose(fp);
    fclose(fp2);
    return 0;
}
