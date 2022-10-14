/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: digit
 File Name: digit.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/14
 Brief description of this program: show the digit of a number
----------------------- END -----------------------
**************************************************/
#include <stdio.h>

int main() {
    int number;
    scanf("%d", &number);
    int numDigit = 0;
    do {
        number /= 10;
        numDigit++;
    } while (number);
    printf("%d", numDigit);
}