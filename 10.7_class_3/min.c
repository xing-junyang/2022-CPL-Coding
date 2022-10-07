/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: min
 File Name: min.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/7
 Brief description of this program: Return the min value of a,b.
----------------------- END -----------------------
**************************************************/
#include <stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a > b) {
        printf("%d", b);
    } else {
        printf("%d", a);
    }
    return 0;
}