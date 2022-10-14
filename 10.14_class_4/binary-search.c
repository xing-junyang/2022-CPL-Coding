/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: binary search
 File Name: binary-search.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/14
 Brief description of this program:
----------------------- END -----------------------
**************************************************/

#include <stdio.h>

const int maxArrayLength = 100;

int findValue(int *array, int low, int high, int key) {
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (key > array[mid]) {
            low = mid + 1;
        } else if (key < array[mid]) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int findValueLeft(int *array, int low, int high, int key) {
    int index = -1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (key > array[mid]) {
            low = mid + 1;
        } else if (key < array[mid]) {
            high = mid - 1;
        } else {
            index = mid;
            high = mid - 1;
        }
    }
    return index;
}

int findValueRight(int *array, int low, int high, int key) {
    int index = -1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (key > array[mid]) {
            low = mid + 1;
        } else if (key < array[mid]) {
            high = mid - 1;
        } else {
            index = mid;
            low = mid + 1;
        }
    }
    return index;
}

int main() {
    int a[maxArrayLength];//the array is sorted.
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int key;
    scanf("%d", &key);
    printf("%d", findValue(a, 1, n, key));
    return 0;
}