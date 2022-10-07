/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: single
 File Name: single.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/7
 Brief description of this program:
----------------------- END -----------------------
**************************************************/
#include <stdio.h>

int a[1000005];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<2*n-1;i++){
        int tmp;
        scanf("%d",&tmp);
        a[tmp]++;
    }
    for(int i=1;i<=10*n;i++){
        if(a[i]==1){
            printf("%d",i);
            return 0;
        }
    }
}