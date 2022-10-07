/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: obstacle
 File Name: obstacle.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/7
 Brief description of this program: ..
----------------------- END -----------------------
**************************************************/
#include <stdio.h>

struct Point {
    int x, y
};

struct Point a, b, c;

int maxx(int a, int b) { return a > b ? a : b; }

int minn(int a, int b) { return a < b ? a : b; }

int abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int inside(int a, int b, int c) {//To see whether c is between a and b
    if ((c - a) < 0 && (c - b) < 0) {
        return 0;
    }
    if ((c - a) > 0 && (c - b) > 0) {
        return 0;
    }
    return 1;
}

int main() {
    scanf("%d%d%d%d%d%d", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
    if (a.x == b.x) {
        int tmp = abs(a.y - b.y);
        if ((c.y > minn(a.y, b.y) && c.y < maxx(a.y, b.y))&&c.x==a.x) {
            printf("%d\n", tmp + 2);
            printf("R");
            for (int i = 1; i <= tmp; i++) {
                if (a.y == minn(a.y, b.y)) {
                    printf("U");
                } else {
                    printf("D");
                }
            }
            printf("L");
            return 0;
        } else {
            printf("%d\n", tmp);
            for (int i = 1; i <= tmp; i++) {
                if (a.y == minn(a.y, b.y)) {
                    printf("U");
                } else {
                    printf("D");
                }
            }
            return 0;
        }
    }
    if (a.y == b.y) {
        int tmp = abs(a.x - b.x);
        if ((c.x > minn(a.x, b.x) && c.x < maxx(a.x, b.x))&&c.y==a.y) {
            printf("%d\n", tmp + 2);
            printf("D");
            for (int i = 1; i <= tmp; i++) {
                if (a.x == minn(a.x, b.x)) {
                    printf("R");
                } else {
                    printf("L");
                }
            }
            printf("U");
            return 0;
        } else {
            printf("%d\n", tmp);
            for (int i = 1; i <= tmp; i++) {
                if (a.x == minn(a.x, b.x)) {
                    printf("R");
                } else {
                    printf("L");
                }
            }
            return 0;
        }
    }
    int xmax, ymax;
    xmax = maxx(a.x, b.x);
    ymax = maxx(a.y, b.y);
    printf("%d\n", abs(a.x - b.x) + abs((a.y - b.y)));
    if (a.x == xmax && a.y == ymax) {
        //1
        if ((inside(a.x, b.x, c.x) && c.y == a.y) || (inside(a.y, b.y, c.y) && c.x == b.x)) {
            for (int i = 1; i <= abs(b.y - a.y); i++) {
                printf("D");
            }
            for (int i = 1; i <= abs(b.x - a.x); i++) {
                printf("L");
            }
            return 0;
        } else {
            for (int i = 1; i <= abs(b.x - a.x); i++) {
                printf("L");
            }
            for (int i = 1; i <= abs(b.y - a.y); i++) {
                printf("D");
            }
            return 0;
        }
    }
    if (a.x == xmax && b.y == ymax) {
        //2
        if ((inside(a.x, b.x, c.x) && c.y == b.y) || (inside(a.y, b.y, c.y) && c.x == a.x)) {
            for (int i = 1; i <= abs(b.x - a.x); i++) {
                printf("L");
            }
            for (int i = 1; i <= abs(b.y - a.y); i++) {
                printf("U");
            }
            return 0;
        } else {
            for (int i = 1; i <= abs(b.y - a.y); i++) {
                printf("U");
            }
            for (int i = 1; i <= abs(b.x - a.x); i++) {
                printf("L");
            }
            return 0;
        }
    }
    if (b.x == xmax && a.y == ymax) {
        //3
        if ((inside(a.x, b.x, c.x) && c.y == a.y) || (inside(a.y, b.y, c.y) && c.x == b.x)) {
            for (int i = 1; i <= abs(b.y - a.y); i++) {
                printf("D");
            }
            for (int i = 1; i <= abs(b.x - a.x); i++) {
                printf("R");
            }
            return 0;
        } else {
            for (int i = 1; i <= abs(b.x - a.x); i++) {
                printf("R");
            }
            for (int i = 1; i <= abs(b.y - a.y); i++) {
                printf("D");
            }
            return 0;
        }
    }
    if (b.x == xmax && b.y == ymax) {
        //4
        if ((inside(a.x, b.x, c.x) && c.y == b.y) || (inside(a.y, b.y, c.y) && c.x == a.x)) {
            for (int i = 1; i <= abs(b.x - a.x); i++) {
                printf("R");
            }
            for (int i = 1; i <= abs(b.y - a.y); i++) {
                printf("U");
            }
            return 0;
        } else {
            for (int i = 1; i <= abs(b.y - a.y); i++) {
                printf("U");
            }
            for (int i = 1; i <= abs(b.x - a.x); i++) {
                printf("R");
            }
            return 0;
        }
    }
}