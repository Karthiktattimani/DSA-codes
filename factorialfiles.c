#include <stdio.h>


unsigned long long factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
 {
    FILE *inputFile, *outputFile;
    int num;
    unsigned long long fact = 1;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        printf("Error opening input file.\n");
        return 1;
    }


    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    while (fscanf(inputFile, "%d", &num) != EOF)
    {
        if (num < 0)
            fprintf(outputFile, "Factorial is not defined for negative numbers.\n");
        else {
            fact = factorial(num);
            fprintf(outputFile, "Factorial of %d = %llu\n", num, fact);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Factorials calculated and saved to output.txt.\n");

    return 0;
}
