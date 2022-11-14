#include <stdio.h>
#include <string.h>

char board[500][500];

void printCube(int x, int y, int z) {
    memset(board, ' ', sizeof(board));
    for (int i = 1; i <= 2 * y + 1; i++) {
        if (i & 1) {
            for (int j = 1; j <= 2 * x + 1; j++) {
                board[i][2 * y + 1 - i + j] = j & 1 ? '+' : '-';
            }
        } else {
            for (int j = 1; j <= 2 * x + 1; j++) {
                board[i][2 * y + 1 - i + j] = j & 1 ? '/' : ' ';
            }
        }
    }
    for (int h = 0; h < z; h++) {
        for (int i = 1; i <= 2 * x + 1; i++) {
            board[2 * y + 2 + 2 * h][i] = i & 1 ? '|' : ' ';
        }
        for (int i = 1; i <= 2 * x + 1; i++) {
            board[2 * y + 2 + 2 * h + 1][i] = i & 1 ? '+' : '-';
        }
        for (int i = 1; i <= 2 * y; i++) {
            board[2 * y + 2 + 2 * h + 1 - i][2 * x + 1 + i] = i & 1 ? '/' : '+';
        }
        for (int i = 1; i <= 2 * y; i++) {
            board[2 * y + 2 + 2 * h - i][2 * x + 1 + i] = i & 1 ? ' ' : '|';
        }
    }
    for (int i = 1; i <= 2 * (y + z) + 1; i++) {
        for (int j = 1; j <= 2 * (x + y) + 1; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        printCube(a, b, c);
    }
}