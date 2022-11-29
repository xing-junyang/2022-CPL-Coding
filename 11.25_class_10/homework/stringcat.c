#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mystrcat(char *dest, char *src, int n) {
    strcpy((dest + n), src);
}

int mystrcmp(char *str1, char *str2) {
    int i = 0;
    int len2 = strlen(str2);
    while (*(str1 + i)) {
        if (i >= len2) {
            return 0;
        }
        if (*(str1 + i) != *(str2 + i)) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; k++) {
        char *str1 = malloc(10000 * sizeof(*str1));
        char *str2 = malloc(10000 * sizeof(*str2));
        scanf("%s", str1);
        scanf("%s", str2);
        int i = 0;
        while (*(str1 + i)) {
            if (mystrcmp(str1 + i, str2)) {
                break;
            }
            i++;
        }
        mystrcat(str1, str2, i);
        puts(str1);
    }
    return 0;
}