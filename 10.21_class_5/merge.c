/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: merge
 File Name: merge.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/21
 Brief description of this program: merge two arrays`
----------------------- END -----------------------
**************************************************/
#include <stdio.h>

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {2, 3, 7, 8, 10};
    int ans[10];
    int l = 0, r = 0, cnt = 0;
    while (l < 5 && r < 5) {
        if (a[l] < b[r]) {
            ans[cnt++] = a[l];
            l++;
        } else {
            ans[cnt++] = b[r];
            r++;
        }
    }
    if (l == 5) {
        while (r < 5) {
            ans[cnt++] = b[r++];
        }
    }
    if (r == 5) {
        while (l < 5) {
            ans[cnt++] = a[l++];
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}