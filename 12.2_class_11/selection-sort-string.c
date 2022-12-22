#include <stdio.h>
#include <string.h>

void print(char *strings[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%s\n", strings[i]);
    }
}

void swapPtr(char **str1, char **str2) {
    char *tmpPtr = *str1;
    *str1 = *str2;
    *str2 = tmpPtr;
}

void selectionSort(char **strings, int len) {
    for (int i = 0; i < len; i++) {
        char *now = strings[i];
        int nowIndex = i;
        for (int j = i + 1; j < len; j++) {
            if (strcmp(now, strings[j]) > 0) {
                now = strings[j];
                nowIndex = j;
            }
        }
        swapPtr(&strings[i], &strings[nowIndex]);
    }
}

int main() {
    char *musicians[] = {
            "Luo Dayou", "Cui Jian", "Dou Wei", "Zhang Chu", "Yao", "Wan Qing", "Zuo Xiao", "ErShou Rose", "Hu Mage",
            "Li Zhi"
    };
    print(musicians, 10);
    selectionSort(musicians, 10);
    printf("\n");
    print(musicians, 10);

    return 0;
}