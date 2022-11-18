/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: radius
 File Name: radius.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/11/18
 Brief description of this program: Introduction to Pointer.
----------------------- END -----------------------
**************************************************/
#include <stdio.h>

/*
 * The definition of Pointer
 * The Pointer is a variable that contains the address of a variable.
 *
 * INT variable can be used as lvalue and rvalue.
 * INT* variable can be used as lvalue, but only can be assigned with an address of int or INT* variable
 *
 */

int main(){
    int radius=10;
    printf("Radius is %d\n",radius);
    printf("The address of radius is %p\n",&radius);

    int *ptrRadius=&radius;
    printf("The address of ptr Radius is %p",&ptrRadius);

    return 0;
}