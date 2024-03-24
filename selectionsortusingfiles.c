#include <stdio.h>
#include <stdio.h>
#include <string.h>
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
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

    int n;
    fscanf(fp, "%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    selectionSort(arr, n);

    for (int i = 0; i < n; i++) {
        fprintf(fp2, "%d ", arr[i]);
    }

    fclose(fp);
    fclose(fp2);

    return 0;
}
