#include<stdio.h>

int main()
{
    int married;
    printf("Enter a number (single:0; married:Non-zero integer): ");
    scanf("%d",&married);
    married==0?printf("Single"):printf("Married");
    return 0;
}