/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: min of a set of numbers
 File Name: minOfASetOfNumbers.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/7
 Brief description of this program: ..
----------------------- END -----------------------
**************************************************/
#include <stdio.h>

const int maxLength=5000;

int min(int a,int b){
    return a>b?b:a;
}

int main(){
    int a[maxLength];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int ans=a[0];
    for (int i=1;i<n;i++){
        ans=min(ans,a[i]);
    }
    printf("%d",ans);
}