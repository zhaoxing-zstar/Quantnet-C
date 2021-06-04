#include <stdio.h>
#include <string.h>
#define MAXLEN 100
#define MAXLINE 100
void Multiply(char *p,int n,int point){
    unsigned an1[MAXLEN],an2[MAXLEN],aResult[MAXLEN];
    int i,j = 0,nLen1 = (int)strlen(p),nLen2 = (int)strlen(p);
    point = point * n;
    memset( an1, 0, sizeof(an1));
    memset( an2, 0, sizeof(an2));
    for( i = nLen1 - 1;i >= 0 ; i --) {
        an1[j] = p[i] - '0';
        an2[j++] = p[i] - '0';
    }//即an1为p本身,an2先定为p
    while(n - 1){
        memset( aResult, 0, sizeof(aResult));
        for( i = 0;i < nLen2; i ++ ) {
            for( j = 0; j < nLen1; j ++ ){
                aResult[i+j] += an2[i]*an1[j];
            }
        }
        for( i = 0; i < MAXLEN; i ++ ) {
            if( aResult[i] >= 10 ) {
                aResult[i+1] += aResult[i] / 10;
                aResult[i] %= 10;
            }
            if( aResult[i] ) nLen2 = i + 1;
        }
        for( i = nLen2 - 1; i >= 0; i -- ) {
            an2[i] = aResult[i];
        }
        n --;
    }//循环n次得到n次幂结果,即an2
    //nLen2为有效数字位数
    int end = 0;
    for( i = 0; i < point; i ++ ) {
        if(an2[i] == 0) {
            end ++;
        }
        else break;
    }
    if(nLen2 < point) {
        printf(".");
        for(j = 0; j < point - nLen2; j ++ ) {
            printf("0");
        }
    }
    for( i = nLen2 - 1; i >= end; i -- ) {
        if(i != point - 1) {
            printf("%d", an2[i]);
        }
        else {
            printf(".%d", an2[i]);
        }
    }
    printf("\n");
}
int main() {
    char F[MAXLINE][10],Num[MAXLINE][10];
    int n[MAXLINE];
    int point[MAXLINE];
    int line = 0,i,j,k;
    while (scanf("%s%d", F[line], &n[line]) == 2){
        k = 0;
        for( i = 0; i < strlen(F[line]); i ++ ) {
            if(F[line][i] == '.') {
                point[line] = (int)strlen(F[line]) - i -1;
            }
        }//point即为原数小数点左移位数
        for( j = 0; (F[line][j] == '0')&&(F[line][j] != '.'); j ++);
        for( i = j; i < strlen(F[line]); i ++ ) {
            if(F[line][i] != '.') {
                Num[line][k] = F[line][i];
                k ++;
            }
        }//Num[line]为数
        line ++;//输入的行数
    }
    for( i = 0; i < line; i ++ ) {
        Multiply(Num[i],n[i],point[i]);
    }
    return 0;
}
