/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: A-change
 File Name: A-change.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/2
 Brief description of this program:
----------------------- END -----------------------
**************************************************/
#include <stdio.h>

const int moneyAvailable[5]={50,20,10,5,1};

int main(){
    int money;
    scanf("%d",&money);
    for(int i=0;i<5;i++){
        printf("%d\n",money/moneyAvailable[i]);
        money%=moneyAvailable[i];
    }
    return 0;
}