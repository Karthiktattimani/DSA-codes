#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    char k[100];
    FILE *fp, *fp2;
    fp = fopen("read.txt", "r");
    fp2 = fopen("output.txt", "a");

    if (fp == NULL || fp2 == NULL) {
        printf("File not found\n");
        return 1;
    }

    int sw;

    fscanf(fp, "%d", &sw);

    switch (sw) {
        case 1:

            fscanf(fp, "%s", s);
            fscanf(fp, "%s", k);
            strcat(s, k);
            fprintf(fp2, "%s", s);
            break;
        case 2:
            fscanf(fp, "%s", s);
            fscanf(fp, "%s", k);

            fprintf(fp2, "\nb/f Copyingf string: %s\n", s);
            strcpy(s, k);
            fprintf(fp2, "Copied string: %s", s);
            break;
        case 3:
            fscanf(fp, "%s", s);
            fscanf(fp, "%s", k);
            int res = strcmp(s, k);
            if (res == 0)
                fprintf(fp2, "\nStrings are equal\n");
            else
                fprintf(fp2, "\nStrings are not equal\n");
            break;
        default:
            printf("Invalid option\n");
            break;
    }

    fclose(fp);
    fclose(fp2);

    return 0;
}
