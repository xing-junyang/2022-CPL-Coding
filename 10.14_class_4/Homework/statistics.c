#include <stdio.h>

char str[5000];
int len;
int upperChar[50], lowerChar[50];

int max(int a, int b) { return a > b ? a : b; }

int main() {
    scanf("%d%*c", &len);
    for (int i = 1; i <= len; i++) {
        scanf("%c", &str[i]);
    }
    int maxx = 0;
    for (int i = 1; i <= len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            upperChar[str[i] - 'A']++;
            maxx = max(maxx, upperChar[str[i] - 'A']);
        } else {
            lowerChar[str[i] - 'a']++;
            maxx = max(maxx, lowerChar[str[i] - 'a']);
        }
    }
    int last = 0;
    while (maxx) {
        for (int i = 0; i < 26; i++) {
            if (lowerChar[i]) {
                if (lowerChar[i] >= maxx) {
                    printf("=");
                } else {
                    printf(" ");
                }
            }
            if (upperChar[i]) {
                if (upperChar[i] >= maxx) {
                    printf("=");
                } else {
                    printf(" ");
                }
            }
            if (lowerChar[i] || upperChar[i]) {
                printf(" ");
                last = i;
            }
        }
        printf("\n");
        maxx--;
    }
    for (int i = 0; i < 26; i++) {
        if (lowerChar[i]) {
            printf("-");
        }
        if (upperChar[i]) {
            printf("-");
        }
        if ((lowerChar[i] || upperChar[i]) && (i != last)) {
            printf("-");
        }
    }
    printf("\n");
    for (int i = 0; i < 26; i++) {
        if (lowerChar[i]) {
            printf("%c", i + 'a');
        }
        if (upperChar[i]) {
            printf("%c", i + 'A');
        }
        if (lowerChar[i] || upperChar[i]) {
            printf(" ");
        }
    }
}