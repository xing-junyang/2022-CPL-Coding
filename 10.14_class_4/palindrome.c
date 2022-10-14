/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: palindrome
 File Name: palindrome.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/14
 Brief description of this program: show whether a string is a palindrome
----------------------- END -----------------------
**************************************************/
#include <stdio.h>

const int LEN=21;
char string[LEN];

int main(){
    scanf("%20s",string);
    int length;
    for(int i=0;i<LEN;i++){
        if(string[i]=='\0'){
            length=i-1;
            break;
        }
    }
    int isPalindrome=1;
    for(int i=0;i<=(length)>>1;i++){
        if(string[i]!=string[length-i]){
            isPalindrome=0;
            break;
        }
    }

    printf("\"%s\" is %sa palindrome.\n",string,isPalindrome?"":"not ");
    return 0;
}