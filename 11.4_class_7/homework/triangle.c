#include <stdio.h>
#include <string.h>

char board[4096][2048];

int n;

void paint(int x, int y, int k) {
    if (k == 1) {
        board[x][y] = ' ', board[x][y + 1] = '/', board[x][y + 2] = '\\', board[x][y + 3] = ' ';
        board[x + 1][y] = '/', board[x + 1][y + 1] = '_', board[x + 1][y + 2] = '_', board[x + 1][y + 3] = '\\';
        return;
    }
    paint(x, y, k - 1);
    paint(x + (1 << (k - 1)), y + (1 << (k - 1)), k - 1);
    paint(x + (1 << (k - 1)), y - (1 << (k - 1)), k - 1);
}

int main() {
    scanf("%d", &n);
    memset(board, ' ', sizeof(board));
    paint(1, (1 << n) - 1, n);
    for (int i = 1; i <= (1 << (n)); i++) {
        for (int j = 1; j <= (1 << (n + 1)); j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}