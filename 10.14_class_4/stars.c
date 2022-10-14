/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: stars
 File Name: stars.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/14
 Brief description of this program:
----------------------- END -----------------------
**************************************************/
#include <stdio.h>

void printChar(char x, int times) {
    for (int i = 1; i <= times; i++) {
        putchar(x);
    }
    return;
}

int main() {
    int lines;
    scanf("%d", &lines);
    for (int i = 1; i <= lines; i++) {
        printChar(' ', lines - i);
        printChar('*', 2 * i - 1);
        printf("\n");
    }
    return 0;
}