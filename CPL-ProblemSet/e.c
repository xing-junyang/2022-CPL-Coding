#include <stdio.h>
#include <stdlib.h>

typedef struct spell {
    int dmg;
    int type;
    int value;
}spell;

spell input[10005];

int cmp(const void *a, const void *b) {
    spell *arg1 = (spell *) a;
    spell *arg2 = (spell *) b;
    if (arg1->value> arg2->value) {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &input[i].dmg, &input[i].type);
        input[i].value=input[i].dmg*(input[i].type?(m+1):1);
    }
    qsort(input+1, n, sizeof(spell), cmp);
    int ans=0;
    for(int i=1;i<=k;i++){
        ans+=input[i].value;
    }
    printf("%d",ans);
    return 0;
}