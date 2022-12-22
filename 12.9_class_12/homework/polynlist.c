#include <stdio.h>

int poly[10005][3];
char name[20];
int alen, blen;
int add[10005];
int minus[10005];
int mul[20010];

int max(int a, int b) { return a > b ? a : b; }

int min(int a, int b) { return a < b ? a : b; }

void print(int *src, int len) {
    int maxx = len;
    for (int i = len; i >= 0; i--) {
        if (src[i]) {
            maxx = i;
            break;
        }
    }
    for (int i = maxx; i >= 0; i--) {
        if (src[i] == 0) {
            continue;
        }
        if (src[i] < 0) {
            if (src[i] == -1) {
                if (i == 1) {
                    printf("-%s", name);
                } else if (i == 0) {
                    printf("-1");
                } else {
                    printf("-%s^%d", name, i);
                }
            } else {
                if (i == 1) {
                    printf("%d%s", src[i], name);
                } else if (i == 0) {
                    printf("%d", src[i]);
                } else {
                    printf("%d%s^%d", src[i], name, i);
                }
            }
        } else {
            if (maxx == i) {
                if (src[i] == 1) {
                    if (i == 1) {
                        printf("%s", name);
                    } else if (i == 0) {
                        printf("1");
                    } else {
                        printf("%s^%d", name, i);
                    }
                } else {
                    if (i == 1) {
                        printf("%d%s", src[i], name);
                    } else if (i == 0) {
                        printf("%d", src[i]);
                    } else {
                        printf("%d%s^%d", src[i], name, i);
                    }
                }
                continue;
            }
            if (src[i] == 1) {
                if (i == 1) {
                    printf("+%s", name);
                } else if (i == 0) {
                    printf("+1");
                } else {
                    printf("+%s^%d", name, i);
                }
            } else {
                if (i == 1) {
                    printf("+%d%s", src[i], name);
                } else if (i == 0) {
                    printf("+%d", src[i]);
                } else {
                    printf("+%d%s^%d", src[i], name, i);
                }
            }
        }
    }
    printf("\n");
}

int main() {
    scanf("%d%d", &alen, &blen);
    scanf("%s", name);
    for (int i = alen; i >= 0; i--) {
        scanf("%d", &poly[i][1]);
    }
    for (int i = blen; i >= 0; i--) {
        scanf("%d", &poly[i][2]);
    }
    for (int i = max(alen, blen); i >= 0; i--) {
        add[i] = poly[i][1] + poly[i][2];
        minus[i] = poly[i][1] - poly[i][2];
    }
    for (int i = alen; i >= 0; i--) {
        if (!poly[i][1]) {
            continue;
        }
        for (int j = blen; j >= 0; j--) {
            mul[i + j] += poly[i][1] * poly[j][2];
        }
    }
    print(add, max(alen, blen));
    print(minus, max(alen, blen));
    print(mul, alen + blen + 1);

    return 0;
}