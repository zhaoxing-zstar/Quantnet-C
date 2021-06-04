#include<stdio.h>

void factorial(int a)
{
    switch(a)
    {
        case 0: printf("1");break;
        case 1: printf("%d",a);break;
        default: printf("%d*",a);factorial(a-1);break;
    }
}
int main()
{
    int a;
    printf("Enter a number, return its factorials\n");
    scanf("%d",&a);
    printf("%d!=",a);
    factorial(a);
    return 0;

}