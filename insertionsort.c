#include <stdio.h>
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

    insertionSort(arr, n);

    for (int i = 0; i < n; i++) {
        fprintf(fp2, "%d ", arr[i]);
    }

    fclose(fp);
    fclose(fp2);

    return 0;
}
