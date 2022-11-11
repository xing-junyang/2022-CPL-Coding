/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: mergesort
 File Name: mergesort.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/11/11
 Brief description of this program: Sort an array with merge sort method
----------------------- END -----------------------
**************************************************/
#include <stdio.h>

const int MaxArrayLength = 1000;

int Array[MaxArrayLength];

void mergeSort(int l, int r, int *Array) {
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    mergeSort(l, mid, Array);
    mergeSort(mid + 1, r, Array);
    int leftPtr = l, rightPtr = mid + 1;
    int tmp[MaxArrayLength], cnt = 0;
    while (leftPtr <= mid || rightPtr <= r) {
        if (leftPtr <= mid && rightPtr <= r) {
            if (Array[leftPtr] > Array[rightPtr]) {
                tmp[++cnt] = Array[rightPtr++];
                continue;
            } else {
                tmp[++cnt] = Array[leftPtr++];
                continue;
            }
        } else {
            if (leftPtr > mid) {
                tmp[++cnt] = Array[rightPtr++];
                continue;
            } else if (rightPtr > r) {
                tmp[++cnt] = Array[leftPtr++];
                continue;
            }
        }
    }
    for(int i=1;i<=cnt;i++){
        Array[l+i-1]=tmp[i];
    }
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &Array[i]);
    }
    mergeSort(1, n, Array);
    for (int i = 1; i <= n; i++) {
        printf("%d ", Array[i]);
    }
    return 0;
}