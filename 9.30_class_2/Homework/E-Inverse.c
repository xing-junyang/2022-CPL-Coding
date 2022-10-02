/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: Inverse
 File Name: E-Inverse.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/2
 Brief description of this program: ..
----------------------- END -----------------------
**************************************************/
#include <stdio.h>

int main(){
    char a[5];
    for(int i=0;i<5;i++){
        scanf("%c",&a[i]);
    }
    printf("%c%c%c%c%c",a[2],a[1],a[0],a[4],a[3]);
}