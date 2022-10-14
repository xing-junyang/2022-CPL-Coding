/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: prime
 File Name: prime.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/14
 Brief description of this program: print primes
----------------------- END -----------------------
**************************************************/
#include <stdio.h>

int prime[10000000];

void calcPrime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!prime[i]) {
            for (int j = 2; i * j <= n; j++) {
                prime[i * j] = 1;
            }
        }
    }
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    calcPrime(n);
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (!prime[i]) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n%d", count);
    return 0;
}