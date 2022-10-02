/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: B-Pi
 File Name: B-Pi.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/2
 Brief description of this program:
----------------------- END -----------------------
**************************************************/
#include <stdio.h>
#include <math.h>

int main(){
    double Pi1,Pi2;
    Pi1=4*(4* atan((double)1/5)- atan((double )1/239));
    Pi2=(log(pow(640320,3)+744))/ sqrt(163);
    printf("%.15lf\n",Pi1);
    printf("%.15lf",Pi2);
    return 0;
}