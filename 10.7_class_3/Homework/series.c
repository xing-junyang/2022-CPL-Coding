/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: series
 File Name: series.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/7
 Brief description of this program: ..
----------------------- END -----------------------
**************************************************/
#include <stdio.h>
#include <math.h>

int main(){
    double x,ans=0;
    int n;
    scanf("%lf%d",&x,&n);
    for(int i=0;i<=n;i++){
        ans+= 4*(pow(-1,i)* pow(x,2*i+1)/(1.0*(2*i+1)));
    }
    printf("%.10lf",ans);
    return 0;
}