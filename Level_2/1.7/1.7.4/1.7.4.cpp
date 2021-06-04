/* print the day of a given day-number */
#include<stdio.h>
void DayName(int i);
int main()
{
    int day_num;
    printf("Please input a day number: ");
    scanf("%d",&day_num);
    DayName(day_num);
    return 0;
}
void DayName(int i)
{
    char day[7][10]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    printf("Day %d is %s",i,day[i-1]);
}