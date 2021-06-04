#include<stdio.h>
#include<ctype.h>

int main()
{
    char s,prev_s=0;       //character and its previous character
    int count_chars=0, count_words=0, count_newlines=0;
    printf("please enter some text:");
    while((s=getchar())!=EOF && s!=4 && s!=26)  // character isn't ctrl+d or ctrl+z
    {
        switch(isspace(s))
        {
            case 0:
                switch(isspace(prev_s) !=0)
                {
                    case 1:count_words++;
                        break;
                }
                switch(prev_s)
                {
                    case 0: count_words++;
                        break;
                }
        }
        switch(s)
        {
            case 10: count_newlines++;
                break;
            case 13: count_newlines++;
                break;
            default:
                switch(prev_s){
                    case 0: count_newlines++;
                        break;

                }
            
        }
        count_chars++;
        prev_s=s;
    }
    printf("Amount of characters:%d\n",count_chars);
    printf("Amount of words:%d\n",count_words);
    printf("Amount of newlines:%d\n",count_newlines);
}