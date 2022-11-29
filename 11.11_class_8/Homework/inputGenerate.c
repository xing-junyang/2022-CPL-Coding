/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: inputGenerate
 File Name: inputGenerate.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/11/18
 Brief description of this program: to generate the large input of buddy.c
----------------------- END -----------------------
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    freopen("inputOfBuddy.txt","w",stdout);
    printf("30 10000\n");
    srand(time(0));
    for(int i=1;i<=10000;i++){
        if(rand()&1){
            printf("A %d %d\n",i,rand()%1000+1);
        }else{
            printf("Q\n");
        }
    }
}