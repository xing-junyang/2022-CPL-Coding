#include <stdio.h>

int flag = 0;
int volume[4], target[4], k;

int minn(int a, int b) { return a < b ? a : b; }

void pour(int nowA, int nowB, int nowC, int step) {
    nowA = minn(volume[1], nowA);
    nowB = minn(volume[2], nowB);
    nowC = minn(volume[3], nowC);
    if (step > k) {
        return;
    }
    if (nowA + nowB + nowC < target[1] + target[2] + target[3]) {
        return;
    }
    if (nowA == target[1] && nowB == target[2] && nowC == target[3]) {
        flag = 1;
        return;
    }
    pour(0, nowA + nowB, nowC, step + 1);
    pour(0, nowB, nowA + nowC, step + 1);
    pour(nowA + nowB, 0, nowC, step + 1);
    pour(nowA, 0, nowC + nowB, step + 1);
    pour(nowA + nowC, nowB, 0, step + 1);
    pour(nowA, nowB + nowC, 0, step + 1);
}

int main() {
    scanf("%d", &k);
    for (int i = 1; i <= 3; i++) {
        scanf("%d", &volume[i]);
    }
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    for (int i = 1; i <= 3; i++) {
        scanf("%d", &target[i]);
    }
    pour(a, b, c, 0);
    printf("%s", flag ? "Yes" : "No");
    return 0;
}