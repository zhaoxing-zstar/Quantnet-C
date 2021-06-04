#include<stdio.h>

float substract(float num1,float num2)
{
    return num1-num2;
}
int main()
{
    float a,b;
    printf("Enter number a and b:\n");
    scanf("%f%f",&a,&b);
    printf("a-b=%.2f",substract(a,b));
}