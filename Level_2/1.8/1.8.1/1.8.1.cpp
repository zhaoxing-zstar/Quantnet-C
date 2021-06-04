/* Struct Article */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* Define struct */
struct Article
{
    int ArtNum;
    int Qut;
    char des[20];
};
void Print(struct Article* pt);
int main()
{
    struct Article* p;
    struct Article art;

    // initialize
    art.ArtNum=10;
    art.Qut=70;
    strcpy(art.des,"an interesting book");
    p=&art;
    Print(p);

}
void Print(struct Article* pt)
{
    printf("Article Number of Art is: %d\n",pt->ArtNum);
	printf("Quantity of Art= is: %d\n",pt->Qut);
	printf("Description of Art is: %s\n",pt->des);
}
