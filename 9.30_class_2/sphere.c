/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: Sphere
 File Name: sphere.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/9/30
 Brief description of this program: compute sphere surface area and volume.
----------------------- END -----------------------
**************************************************/
#include <stdio.h>

const double PI = 3.14159265358;

int main(){
    int radius = 100;
    printf("%15.4lf = circumference\n", radius*radius*4*PI);
    printf("%15.4lf = area\n",PI*radius*radius*radius*4/3);
    return 0;
}