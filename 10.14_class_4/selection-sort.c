/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: selection sort
 File Name: selection-sort.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/14
 Brief description of this program:
----------------------- END -----------------------
**************************************************/
#include <stdio.h>

const int maxArrayLength = 100;
int array[maxArrayLength];

void swap(int *a, int *b) {
    int tmp;
    tmp = *b;
    *b = *a;
    *a = tmp;
    return;
}

int main() {
    int n=0;
//    scanf("%d", &n);
    while(scanf("%d",&array[++n])!=EOF);
    n--;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &array[i]);
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", array[i]);
    }

    //selection sort
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i; j <= n; j++) {
            if (array[i] > array[j]) {
                swap(&array[i], &array[j]);
            }
        }
    }
    //end of selection sort

    for (int i = 1; i <= n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}