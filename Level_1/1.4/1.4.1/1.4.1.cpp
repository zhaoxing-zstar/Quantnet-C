#include<stdio.h>
#include<ctype.h>

int main()
{
    char s,prev_s=0;       //character and its previous character
    int count_chars=0, count_words=0, count_newlines=0;
    printf("please enter some text:");
    while((s=getchar())!=EOF && s!=4 && s!=26)  // character isn't ctrl+d or ctrl+z
    {
        if ((isspace(s)==0) && (isspace(prev_s) || prev_s==0))
        {
            count_words++;
        }
        if (s==10 || s==13 || prev_s==0)
        {
            count_newlines++;
        }
        count_chars++;
        prev_s=s;
    }
    printf("Amount of characters:%d\n",count_chars);
    printf("Amount of words:%d\n",count_words);
    printf("Amount of newlines:%d\n",count_newlines);
}