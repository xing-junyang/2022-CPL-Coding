#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main(){
    freopen("a.in","w",stdout);
    printf("1000");
    srand(time(0));
    for(int i=1;i<=1000;i++){
        int ju=rand()%3;
        if(ju==0){
            putchar('.');
        }else if(ju==1){
            putchar('A');
        }else{
            putchar('B');
        }
    }
}