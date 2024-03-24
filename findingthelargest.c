#include <stdio.h>

int main() {
    int a[100];
    FILE *fp, *fp2;
    fp = fopen("read.txt", "r");
    fp2 = fopen("output.txt", "a");

    if (fp == NULL || fp2 == NULL) {
        printf("File not found\n");
        return 1;
    }

    int n, sw;
    int s = 0;
    int min, max;

    fscanf(fp, "%d", &n);
    printf("%d\n", n);


    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &a[i]);
        fprintf(fp2, "%d\t", a[i]);
    }



for(int i=0;i<2;i++)
  fscanf(fp, "%d", &sw);
{    switch (sw) {
        case 1:

            max = a[0];
            for (int i = 1; i < n; i++) {
                if (a[i] > max) {
                    max = a[i];
                }
            }
            fprintf(fp2, "\nMax: %d\n", max);
            break;
        case 2:
              min = a[0];
            for (int i = 1; i < n; i++) {
                if (a[i] < min) {
                    min = a[i];
                }
            }
            fprintf(fp2, "\nMin: %d\n", min);
            break;
        case 3:

            for (int i = 0; i < n; i++) {
                s += a[i];
            }
            fprintf(fp2, "\nSum: %d\n", s);

            double avg = (double)s / n;
            fprintf(fp2, "Average: %lf\n", avg);
            break;
        default:
            printf("Invalid switch case\n");
    }
}
    fclose(fp);
    fclose(fp2);
    return 0;

}
