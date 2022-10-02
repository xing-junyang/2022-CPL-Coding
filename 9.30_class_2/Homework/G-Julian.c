/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: julian
 File Name: G-Julian.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/2
 Brief description of this program: ,.
----------------------- END -----------------------
**************************************************/
#include <stdio.h>
#include <math.h>

int main(){
    int year,month,day;
    double a,y,m;
    long long JDN;
    scanf("%d%d%d",&year,&month,&day);
    a= floor((14.0-month)/12);
    y=year+4800-a;
    m=month+12*a-3;
    JDN=day+ floor((153.0*m+2)/5)+365*y+ floor(y/4)- floor(y/100)+ floor(y/400)-32045;
    printf("%lld",JDN);
}