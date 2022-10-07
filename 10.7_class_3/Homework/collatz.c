/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: collatz
 File Name: collatz.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/7
 Brief description of this program: ..
----------------------- END -----------------------
**************************************************/
#include <stdio.h>

int maxx(int a,int b){return a>b?a:b;}

int main(){
    int n;
    scanf("%d",&n);
    int max=n,ans=0;
    while (n!=1){
        if(n%2){
            n=n*3+1;
            max=maxx(max,n);
        }else{
            n>>=1;
        }
        ans++;
    }
    printf("%d %d",ans,max);
    return 0;
}