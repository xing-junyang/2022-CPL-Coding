#include <stdio.h>
#include <stdlib.h>

typedef struct wine {
    int v;
    int w;
} wine;

wine all[10005];

int cmp(const void *ina, const void *inb) {
    wine a = *(wine *) ina;
    wine b = *(wine *) inb;
    if (a.v > b.v) {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    int n, L;
    scanf("%d%d", &n, &L);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &all[i].v);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &all[i].w);
    }
    qsort(all + 1, n, sizeof(wine), cmp);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (L > all[i].w) {
            ans += all[i].v * all[i].w;
            L -= all[i].w;
        } else {
            ans += all[i].v * L;
            break;
        }
    }
    printf("%d", ans);
    return 0;
}