/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: mul
 File Name: mul.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/9/30
 Brief description of this program:
----------------------- END -----------------------
**************************************************/
#include <stdio.h>

int main(){
    const double MUL=6.02e23;
    const int MOL_PER_GRAM = 32;
    int mass=6;
    double quantity=mass*1.0/MOL_PER_GRAM*MUL;

    printf("Quantity = %.3e\nQuantity = %.5g\n",quantity,quantity);
    return 0;
}