#include <stdio.h>
#include<stdlib.h>

int main() {
    FILE *sp, *sp2;
    sp = fopen("read.txt", "r");
    sp2 = fopen("output.txt", "w");

    if (sp == NULL || sp2 == NULL) {
        printf("File not found\n");
        return 1;
    }

    int n, s = 0;
    fscanf(sp, "%d", &n);
    printf("%d\n", n);

    while (n != 0) {
        int r = n % 10;
        s = s * 10 + r;
        n /= 10;
    }

    printf("%d\n", s);
    fprintf(sp2, "%d\n", s);

    fclose(sp);
    fclose(sp2);

    return 0;
}
