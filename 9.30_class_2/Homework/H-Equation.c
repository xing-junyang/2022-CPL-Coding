/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: Equation
 File Name: H-Equation.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/2
 Brief description of this program: ..
----------------------- END -----------------------
**************************************************/
#include <stdio.h>
#include <math.h>

double realPow(double a,int b){//There is a fake one in math.h.
    //1=2 2=3 3=1/3
    if(b==1){
        if(a<0){
            return pow(-a,2);
        }
        return pow(a,2);
    }
    if(b==2){
        if(a<0){
            return -pow(-a,3);
        }
        return pow(a,3);
    }
    if(b==3){
        if(a<0){
            return -pow(-a,1.0/3);
        }
        return pow(a,1.0/3);
    }
}

int main(){
    int p,q;
    scanf("%d%d",&p,&q);
  //  printf("%lf\n", realPow((1.0)*q/2,1));
    double delta= realPow((1.0)*q/2,1)+realPow((1.0)*p/3,2);
    double ans=realPow((-1.0*q/2+ sqrt(delta)),3)+realPow((-1.0*q/2- sqrt(delta)),3);
    printf("%.3lf",ans);
}