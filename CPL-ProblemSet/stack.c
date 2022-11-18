/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: Stack
 File Name: stack.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/11/16
 Brief description of this program: To build a stack
----------------------- END -----------------------
**************************************************/
#include <stdio.h>
#include <string.h>

char stack[10005];
int top;

void push(int m) {
    stack[++top] = m;
    return;
}

void pop() {
    if (!top) {
        printf("Empty\n");
        return;
    }
    top--;
    return;
}

void showTop() {
    if (!top) {
        printf("Empty\n");
        return;
    }
    printf("%c\n", stack[top]);
    return;
}

void print() {
    if (!top) {
        printf("Empty\n");
        return;
    }
    for (int i = top; i >= 1; i--) {
        printf("| %c |\n", stack[i]);
    }
    printf("|===|");
    return;
}

int main() {
    int n;
    char str[10];
    scanf("%d%*c", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str);
        if (!strcmp(str, "pop")) {
            pop();
        } else if (!strcmp(str, "top")) {
            showTop();
        } else if (!strcmp(str, "print")) {
            print();
        } else {
            char m;
            scanf("%*c%c", &m);
            push(m);
        }
    }
    return 0;
}