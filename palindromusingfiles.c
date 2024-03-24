#include <stdio.h>
#include<stdlib.h>
int main() {
    FILE *sp,*sp2;
    int n, r, s = 0;

    sp2=fopen("read.txt","r");
    fscanf(sp2,"%d", &n);
    int o = n;

    sp=fopen("output.txt","w");

    if(sp==NULL || sp2==NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (n != 0) {
        r = n % 10;
        s = s * 10 + r;
        n = n / 10;
    }

    if (o == s) {
        printf("Palindrome\n");
        fprintf(sp, "%d Palindrome\n",o);
    } else {
        printf("Not a Palindrome\n");
        fprintf(sp, " %d Not a Palindrome\n",o);
    }

    fclose(sp);

    fclose(sp2);
    return 0;
}
