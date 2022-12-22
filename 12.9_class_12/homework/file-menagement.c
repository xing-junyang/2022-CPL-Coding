#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct file {
    char name[20];
    char fatherName[20];
    int father;
    int child[5];//begins from 0;
    int chileCnt;
    bool isRemoved;
    bool isRoot;
} File;
int n;
File fileSys[1000];

void construct() {
    for (int i = 1; i <= n; i++) {
        File now = fileSys[i];
        if (strcmp(now.fatherName, "~~~") == 0) {
            now.isRoot = 1;
            continue;
        }
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }
            if (strcmp(now.fatherName, fileSys[j].name) == 0) {
                fileSys[j].child[fileSys[j].chileCnt++] = i;
                now.father = j;
                break;
            }
        }
    }
    return;
}

void rm(int x) {
    fileSys[x].isRemoved = 1;
}

int query(int x) {
    int sum = 0;
    if (fileSys[x].isRemoved) {
        return 0;
    }
    if (fileSys[x].chileCnt == 0) {
        return 1;
    }
    for (int i = 0; i < fileSys[x].chileCnt; i++) {
        sum += query(fileSys[x].child[i]);
    }
    return sum + 1;
}

int main() {
    int q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%s%s", fileSys[i].name, fileSys[i].fatherName);
        fileSys[i].chileCnt = 0;
        fileSys[i].isRoot = 0;
        fileSys[i].isRemoved = 0;
    }
    construct();
    for (int i = 1; i <= q; i++) {
        char str1[20];
        char str2[20];
        scanf("%s%s", str1, str2);
        if (strcmp(str1, "remove") == 0) {
            for (int j = 1; j <= n; j++) {
                if (strcmp(str2, fileSys[j].name) == 0) {
                    rm(j);
                    //printf("%d\n",fileSys[j].isRemoved);
                    break;
                }
            }
        } else {
            for (int j = 1; j <= n; j++) {
                if (strcmp(str2, fileSys[j].name) == 0) {
                    printf("%d\n", query(j));
                    break;
                }
            }
        }
    }

}