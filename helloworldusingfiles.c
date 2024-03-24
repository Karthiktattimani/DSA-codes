#include<stdio.h>
int main()
{
    FILE *sp;
    sp=fopen("output.txt","w");
    if(sp==NULL)
    {
        printf("not found\n");
    }
  fprintf(sp,"Hello world\n");
  fclose(sp);
  return 0;
}
