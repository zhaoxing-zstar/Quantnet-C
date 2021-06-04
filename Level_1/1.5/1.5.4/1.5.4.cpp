#include<stdio.h>

void printnumber(int a);

int main()
{
    float a;
	printf("Please input an integer with less than or equal to 8 digits: ");
	scanf("%f",&a);
	printnumber(a);
    return 0;
}
void printnumber(int i)
{
    if(i<0)
    {
        i*=-1;
        putchar('-');
    }
    if ((i / 10) != 0) {
		printnumber((i / 10));  //recursive call to function
		putchar('0' + (i % 10));  
	} else {
		putchar('0' + i);
	}

}