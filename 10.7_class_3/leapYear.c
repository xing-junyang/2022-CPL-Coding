/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: leap year
 File Name: leapYear.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/7
 Brief description of this program: ..
----------------------- END -----------------------
**************************************************/
#include <stdio.h>

int main() {
    int year;
    scanf("%d", &year);
    if (!(year % 400)) {
        printf("Yes.");
    } else {
        if (!(year % 100)) {
            printf("No.");
        } else {
            if (year % 4) {
                printf("No.");
            } else {
                printf("Yes.");
            }
        }
    }
    return 0;
}