#include<stdio.h>

int main()
{
    int num;
    printf("Enter a number:");
    scanf("%d",&num);
    num=num>>2; //Shift two place to right
    printf("The number shifted two places to the right is: %d \n",num);

    //output an indication of whether a logical or arithmetic shift is performed

    if(num<0)
    {
        printf("Input number was negative; arithmetic shift; 1 shifted in at left side.\n");
    }
    else{
        printf("Input number was positive; logical shift; 0 shifted at left side.\n");
    }

}