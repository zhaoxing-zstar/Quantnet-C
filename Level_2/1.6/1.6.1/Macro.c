/*
Macro.c
contains two print macro calls
PRINT1 prints the variable a, PRINT2 prints the variables a and b.
*/
#include<stdio.h>
#include "Defs.h"

int main()
{
    float a,b;
    printf("a=?\n");
    scanf("%f",&a);
    printf("b=?\n");
    scanf("%f",&b);
    PRINT1(a);
    PRINT2(a,b);
    return 0;
}