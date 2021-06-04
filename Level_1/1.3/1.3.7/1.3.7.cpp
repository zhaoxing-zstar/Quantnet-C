#include<stdio.h>

int main()
{
    int number,n;
    printf("Enter a number:\n");
    scanf("%d",&number);
    printf("Enter the the power n (2^n):\n");
    scanf("%d",&n);
    number=number<<n;       //shift to the left
    printf("the result is:%d",number);
    return 0;
}