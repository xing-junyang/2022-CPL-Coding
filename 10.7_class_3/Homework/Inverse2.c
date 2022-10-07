/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: inverse2
 File Name: Inverse2.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/7
 Brief description of this program:
----------------------- END -----------------------
**************************************************/
#include <stdio.h>

char a[10000007];

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        a[i]=getchar();
    }
    int k;
    scanf("%d",&k);
    for(int i=k-1;i>=0;i--){
        putchar(a[i]);
    }
    for(int i=n-1;i>=k;i--){
        putchar(a[i]);
    }
    return 0;
}