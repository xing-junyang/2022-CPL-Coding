#include <stdio.h>

typedef struct box {
    int xFir, xSec, yFir, ySec;
    int h;
} box;

box Box;

void rotate(char direction) {
    if (direction == 'D') {
        int tmp = Box.ySec - Box.yFir;
        Box.yFir = Box.ySec;
        Box.ySec += Box.h;
        Box.h = tmp;
    } else if (direction == 'W') {
        int tmp = Box.xSec - Box.xFir;
        Box.xSec = Box.xFir;
        Box.xFir -= Box.h;
        Box.h = tmp;
    } else if (direction == 'A') {
        int tmp = Box.ySec - Box.yFir;
        Box.ySec = Box.yFir;
        Box.yFir -= Box.h;
        Box.h = tmp;
    } else if (direction == 'S') {
        int tmp = Box.xSec - Box.xFir;
        Box.xFir = Box.xSec;
        Box.xSec += Box.h;
        Box.h = tmp;
    }
    return;
}

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    Box = (box) {0, a, 0, b, c};
    getchar();
    char str[1004];
    gets(str);
    for (int i = 0; str[i]; i++) {
        rotate(str[i]);
    }
    printf("%d %d %d %d", Box.xFir, Box.xSec, Box.yFir, Box.ySec);
    return 0;
}