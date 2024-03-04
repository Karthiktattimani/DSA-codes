#include <stdio.h>

float addreal(float, float);
float addimg(float, float);

int main()
{
    float real1, img1, real2, img2, sumreal, sumimg;

    printf("Enter real and img of the first number:\n");
    scanf("%f %f", &real1, &img1);

    printf("Enter real and img of the second number:\n");
    scanf("%f %f", &real2, &img2);

    sumreal = addreal(real1, real2);
    sumimg = addimg(img1, img2);

    printf("Sum: %f + %fi", sumreal, sumimg);

    return 0;
}

float addreal(float num1, float num2)
{
    return num1 + num2;
}

float addimg(float num1, float num2)
{
    return num1 + num2;
}
