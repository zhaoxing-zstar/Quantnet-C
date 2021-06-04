/*  display the input characters */
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
    int c;
    while((c=getchar())!=1) //while CTRL+A is not entered
    {
        putchar(c);
    }
    if (c==1)
    {
        printf("CTRL + A is a correct ending.");
    }
    return 0;
}