#include<stdio.h>

int main()
{
    float current_c;

    printf("Fahrenheit \t Celsius\n");

    for(int i=0;i<=19;i++)
    {
        current_c=(i*float(9)/5+32);
        printf("%d \t %10.1f \n",i,current_c);
    }
    
    return 0;
}