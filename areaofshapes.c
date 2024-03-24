#include<stdio.h>
#include<math.h>

void areasqr(FILE *fp, FILE *fp2) {
    int s,a=0;
    fscanf(fp,"%d",&a);
    s = a * a;
    fprintf(fp2,"%d\n",s);
}

void arearec(FILE *fp, FILE *fp2) {
    int s1,s2,a=0;
    fscanf(fp,"%d %d",&s1,&s2);
    a = s1 * s2;
    fprintf(fp2,"%d\n",a);
}

void areatri(FILE *fp, FILE *fp2) {
    int b,h,a=0;
    fscanf(fp,"%d %d",&b,&h);
    a = 0.5 * b * h;
    fprintf(fp2,"%d\n",a);
}

void areac(FILE *fp, FILE *fp2) {
    int r;
    fscanf(fp,"%d",&r);
    double a = 3.14 * r * r;
    fprintf(fp2,"%lf\n",a);
}

int main() {
    FILE *fp,*fp2;
    fp = fopen("read.txt","r");
    fp2 = fopen("output.txt","a");

    if(fp == NULL || fp2 == NULL) {
        printf("File not found\n");
        return 1;
    }

    int n;
    fscanf(fp,"%d",&n);
    char shape;
        fscanf(fp," %c",&shape);
        if(shape=='s') {
            areasqr(fp, fp2);
        } else if(shape == 'r') {
            arearec(fp, fp2);
        } else if(shape == 'c') {
            areac(fp, fp2);
        } else if(shape == 't') {
            areatri(fp, fp2);
        } else {
            printf("Invalid shape\n");
        }

    fclose(fp);
    fclose(fp2);
    return 1;
}
