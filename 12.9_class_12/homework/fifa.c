#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct team {
    char name[30];
    int totAtk;
    int totDef;
    int totTac;
} Team;

Team table[1005];
int teamCnt;

int cmpAtk(const void *left, const void *right) {
    Team *leftP = left;
    Team *rightP = right;
    if (leftP->totAtk > rightP->totAtk) {
        return -1;
    }
    return 1;
}

int cmpDef(const void *left, const void *right) {
    Team *leftP = left;
    Team *rightP = right;
    if (leftP->totDef > rightP->totDef) {
        return -1;
    }
    return 1;
}

int cmpTac(const void *left, const void *right) {
    Team *leftP = left;
    Team *rightP = right;
    if (leftP->totTac > rightP->totTac) {
        return -1;
    }
    return 1;
}

void print() {
    for (int i = 1; i <= teamCnt; i++) {
        printf("%s ", table[i].name);
    }
    printf("\n");
}

int main() {
    scanf("%d", &teamCnt);
    memset(table, 0, sizeof(table));
    for (int k = 1; k <= teamCnt; k++) {
        scanf("%s", table[k].name);
        for (int i = 1; i <= 11; i++) {
            int a, b, c;
            scanf("%*s%d%d%d", &a, &b, &c);
            table[k].totAtk += a;
            table[k].totDef += b;
            table[k].totTac += c;
        }
    }
    qsort(table + 1, teamCnt, sizeof(Team), cmpAtk);
    print();
    qsort(table + 1, teamCnt, sizeof(Team), cmpDef);
    print();
    qsort(table + 1, teamCnt, sizeof(Team), cmpTac);
    print();

    return 0;
}