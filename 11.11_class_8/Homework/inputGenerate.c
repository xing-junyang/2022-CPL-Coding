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

int main(){
    freopen("inputOfBuddy.txt","w",stdout);
    printf("30 100000\n");
    for(int i=1;i<=99999;i++){
        printf("A %d 1\n",i);
    }
    printf("Q\n");
}