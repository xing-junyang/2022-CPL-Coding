/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: gravity
 File Name: F-Gravity.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/2
 Brief description of this program: ..
----------------------- END -----------------------
**************************************************/
#include <stdio.h>
#include <math.h>

const double gravityConstant=6.674e-11;
const double massTilnel=77.15;

int main(){
    double mass,r;
    scanf("%lf%lf",&mass,&r);
    //printf("%lf %lf\n",mass,r);
    double ans;
    ans=(gravityConstant*mass*massTilnel)/pow(r,2);
    printf("%.3e",ans);
    return 0;
}