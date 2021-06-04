/*  display the input characters */
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAXLEN 100
int main()
{
    int c;
    char file_path[MAXLEN];
    FILE *fp=NULL;
    printf("Input the file you want to save the inputs:\n");
    scanf("%s",file_path);
    fp=fopen(file_path,"w");
    while((c=getchar())!=1) //while CTRL+A is not entered
    {
        fputc(c,fp);        //output the contents to specified file
    }
    if (c==1)
    {
        printf("CTRL + A is a correct ending.");
    }
    fclose(fp);
    return 0;
}