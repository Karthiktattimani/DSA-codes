#include <stdio.h>
#include<stdlib.h>
#include <stdio.h>
#include<stdlib.h>
int  main()
{
    FILE *fp,*fp2;
    fp2=fopen("input.txt","r");
    fp=fopen("write6.txt","w");
    if(fp==NULL || fp2==NULL)
    {
        printf("notfound\n");
    }
  int a,f=1;
  fscanf(fp2,"%d",&a);
  for(int i=1;i<=a;i++)
  {

    f=f*i;

  }
  fprintf(fp,"%d",f);
  fclose(fp);
  fclose(fp2);
}
