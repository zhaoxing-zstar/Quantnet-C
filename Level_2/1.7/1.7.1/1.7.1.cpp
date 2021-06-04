/*
1.7.1.cpp
Swap function using pointers
*/
#include<stdio.h>
#include<stdlib.h>

void Swap(float* a,float* b)
{   float temp;
    temp=*a; *a=*b; *b=temp;

}
int main()
{
    float *a,*b,c,d;
    a=(float *)malloc(sizeof(float));
    b=(float *)malloc(sizeof(float));
    printf("a,b=?\n");
    scanf("%f,%f",a,b);
    Swap(a,b);
    printf("After Swaping, a=%f, b=%f",*a,*b);
}