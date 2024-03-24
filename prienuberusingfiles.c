#include<stdio.h>
#include<stdlib.h>

int main()
{
  FILE *fp, *fp2;
  int flag=0;
    fp = fopen("read.txt", "r");
    fp2 = fopen("write.txt", "w");
    int n;
     if (fp == NULL || fp2 == NULL) {
        printf("File not found\n");
        return 1;
    }
    fscanf(fp,"%d",&n);
    printf("%d",n);
    if(n==0 || n==1)
    {

        flag=1;
    }
    for(int i=2;i<=n/2;++i)
    {
      if(n%i==0)
      {
        flag=1;
        break;
      }


    }
 if(flag==0)
 {
    fprintf(fp2," %d a prime no",n);
 }
 else if(flag==1)
 {
 fprintf(fp2," %d not a prime no",n);
}
fclose(fp);
fclose(fp2);
}
