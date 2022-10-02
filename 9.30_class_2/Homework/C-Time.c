/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: Time
 File Name: C-Time.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/2
 Brief description of this program: ...
----------------------- END -----------------------
**************************************************/
#include <stdio.h>

int main(){
    char month[15],weekday[10];
    int day,year,hour,minute,second;
    scanf("%s %d%d%s %d%d%d",month,&day,&year,weekday,&hour,&minute,&second);
    printf("%.3s %.3s %.2d %.2d:%.2d:%.2d %.4d",weekday,month,day,hour,minute,second,year);
    return 0;
}