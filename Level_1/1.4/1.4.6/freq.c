#include<stdio.h>

int main()
{
    char c;
    int count_0=0,count_1=0,count_2=0,count_3=0,count_4=0,count_other=0;
    printf("Enter some numbers:");
    while((c=getchar())!=4 && c!=26 && c!=EOF)
    {
        switch (c)
        {
            case 48: count_0++;break;
            case 49: count_1++;break;
            case 50: count_2++;break;
            case 51: count_3++;break;
            case 52: count_4++;break;
            default:count_other++;
        }
    }
    printf("Count_0:%d\nCount_1:%d\nCount_2:%d\nCount_3:%d\nCount_4:%d\n",count_0,count_1,count_2,count_3,count_4);
    printf("Count_others:%d\n",count_other);
    return 0;
}