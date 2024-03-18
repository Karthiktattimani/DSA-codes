#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void readAndPrintFile()
{
    FILE* file = fopen("output.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }
    char ch;

    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
    }

    fclose(file);
}

// Function to write data to a file
void writeToFile(int data)
{
    FILE* file = fopen("output.txt", "a+");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "%d\n", data); // Added newline character to separate numbers

    fclose(file);
}

int main()
{
    readAndPrintFile();
    printf("Enter the number of elements to be generated\n");
    int n;
    scanf("%d",&n);
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        int data=rand();
        writeToFile(data);
    }
    return 0; // Added return statement
}
