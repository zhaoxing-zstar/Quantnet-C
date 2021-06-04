#include<stdio.h>

int main(void)
{
    float height, base;
    printf("Please enter the height and base of a right triangle:\n");
    scanf("%f %f",&height,&base);
    printf("The surface area of the right triangle is: %f.\n",0.5*height*base);
    return 0;
}