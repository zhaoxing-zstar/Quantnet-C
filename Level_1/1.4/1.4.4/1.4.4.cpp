#include<stdio.h>

int main()
{
    int step_size, start_fa, end_fa;
    float celsius, current_fa;

    printf("The start temp in Fahrenheit: \n");
    scanf("%d",&start_fa);
    printf("The end temp in Fahrenheit: \n");
    scanf("%d", &end_fa);
    printf("The step_size?\n");
    scanf("%d",&step_size);

    printf("Fahrenheit \t Celsius\n");

    current_fa=start_fa;
    while(current_fa <= end_fa)
    {
        celsius= float(5)/9 * (current_fa-32);
        printf("%10.1f \t %10.1f\n", current_fa, celsius);
        current_fa+=step_size;
    }
    return 0;
}