#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    freopen("in","w",stdout);
    printf("500000 500000\n");
    srand(time(0));
    for(int i=1;i<=500000;i++){
        int len=rand()%100+1;
        for(int j=1;j<=len;j++){
            char ch;
            while(!isalpha(ch=rand()%128));
            putchar(ch);
        }
        printf("\n");
    }
    for(int i=1;i<=500000;i++){
        int len=rand()%9+1;
        for(int j=1;j<=len;j++){
            char ch;
            while(!isalpha(ch=rand()%128));
            putchar(ch);
        }
        printf("\n");
    }
}