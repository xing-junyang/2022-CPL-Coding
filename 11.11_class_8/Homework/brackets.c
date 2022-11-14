#include <stdio.h>
#include <string.h>

char stack[1000005], str[1000005];
int cnt;

int isValid(char *s) {
    cnt = 0;
    memset(stack, 0, sizeof stack);
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++cnt] = s[i];
        } else {
            if (cnt == 0) {
                return 0;
            }
            if (s[i] == ')') {
                if (stack[cnt] == '(') {
                    cnt--;
                } else {
                    return 0;
                }
            } else if (s[i] == ']') {
                if (stack[cnt] == '[') {
                    cnt--;
                } else {
                    return 0;
                }
            } else if (s[i] == '}') {
                if (stack[cnt] == '{') {
                    cnt--;
                } else {
                    return 0;
                }
            }
        }
    }
    if (cnt) {
        return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++) {
        memset(str, 0, sizeof str);
        gets(str);
        printf("%s\n", isValid(str) ? "True" : "False");
    }
    return 0;
}