#include<stdio.h>
#include "Defs.h"

int main()
{
    float x,y,z;
    printf("x,y,z=?\n");
    scanf("%f%f%f",&x,&y,&z);
    printf("Max(x,y)=%5.2f\n",MAX2(x,y));
    printf("Max(x,y,z)=%5.2f",MAX3(x,y,z));
    return 0;


}