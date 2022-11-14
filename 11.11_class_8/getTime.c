/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: getTime
 File Name: getTime.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/11/11
 Brief description of this program: calc time expired
----------------------- END -----------------------
**************************************************/
#include <stdio.h>
#include <time.h>

int fib(int n){
    if(n==1||n==2){
        return 1;
    }
    return (fib(n-1)+fib(n-2))%1007;
}

int main(){
    clock_t Start=clock();
    fib(43);
    clock_t End=clock();
    printf("%f",((double )End-Start)/CLOCKS_PER_SEC);
    return 0;
}