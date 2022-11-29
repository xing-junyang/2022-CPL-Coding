//
// Created by 25127 on 2022/11/19.
//
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define N 10005

void moveBehind(int memory[], int illuminate[], int ID[], int k);

int main() {
    freopen("inputOfBuddy.txt", "r", stdin);
    freopen("out123.txt", "w", stdout);
    int n, q;
    scanf("%d %d", &n, &q);
    getchar();
    int memory[N] = {0};
    int illuminate[N] = {0};
    int ID[N] = {0};
    int move[3][N] = {0};
    for (int i = 0; i < q; i++) {
        char m;
        scanf("%c", &m);
        if (m == 'Q') {
            move[0][i] = 2;
            getchar();
        } else if (m == 'A') {
            move[0][i] = 1;
            int id, e;
            scanf("%d %d", &id, &e);
            getchar();
            move[1][i] = id;
            move[2][i] = e;
        }
    }
    memory[0] = n;
    illuminate[0] = 1;
    for (int i = 0; i < q; i++) {

        if (move[0][i] == 1) {
            bool found = false;
            for (int k = 0; illuminate[k] != 0; k++) {
                if ((move[2][i] > (int) pow(2, memory[k] - 1) && move[2][i] <= (int) pow(2, memory[k]) &&
                     move[2][i] != 1) ||
                    (move[2][i] == 1 && memory[k] == 0)) {
                    if (ID[k] == 0) {
                        ID[k] = move[1][i];
                        found = true;
                        break;
                    }
                }
            }
            if (found == false) {
                bool foundBig = false;
                int k = 0;
                while (foundBig == false) {
                    if ((int) pow(2, memory[k]) > move[2][i] && ID[k] == 0) {
                        foundBig = true;
                    } else {
                        k++;
                    }
                }
                while (((int) pow(2, memory[k] - 1) >= move[2][i] && move[2][i] != 1) ||
                       (move[2][i] == 1 && memory[k] > 0)) {
                    moveBehind(memory, illuminate, ID, k);
                }
                ID[k] = move[1][i];
            }
        } else {
            int sum = 0;
            for (int j = 0; illuminate[j] != 0; j++) {
                sum++;
            }
            printf("%d\n", sum);
            for (int j = 0; j < sum; j++) {
                printf("%d ", ID[j]);
            }
            printf("\n");
        }
    }
    return 0;
}

void moveBehind(int memory[], int illuminate[], int ID[], int k) {
    int length = 0;
    for (int j = 0; illuminate[j] != 0; j++) {
        length++;
    }
    illuminate[length] = 1;
    for (int p = length; p > k + 1; p--) {
        memory[p] = memory[p - 1];
        ID[p] = ID[p - 1];
    }
    ID[k + 1] = 0;
    memory[k + 1] = memory[k] - 1;
    memory[k] = memory[k] - 1;
}