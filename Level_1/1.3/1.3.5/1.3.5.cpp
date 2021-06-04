#include<stdio.h>

int main()
{
    printf("This program is designed to show the differences between i-- and --i\n");
    float i1=10.0,i2=10.0,result1,result2;
    printf("The initial value of i=%f\n",i1);
    result1=--i1;
    result2=i2--;
    printf("Do --i, the result is: %f\n",result1);
    printf("Do i--, the result is: %f\n",result2);   
}
