#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct args {
    char c;
    bool isArg;//0 for no args;
} args;

void print(char *str) {
    int i = 0;
    while (*(str + i)) {
        putchar(*(str + i));
        i++;
    }
    return;
}

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt","w",stdout);

    char *output = malloc(10000 * sizeof(*output));
    int outputPtr = 0;
    char *str = malloc(200 * sizeof(*str));
    gets(str);
    int len = strlen(str);
    args *rules = malloc(200*sizeof (*rules));//begins from 1;
    int rulesCount=0;
    for (int i = 0; i < len; i++) {
        if (*(str + i) != ':') {
            (*(rules+(++rulesCount)))= (args) {*(str + i), 0};
        } else {
            (*(rules+rulesCount)).isArg = 1;
        }
    }

    char *fileName = malloc(1024 * sizeof(*fileName));
    scanf("%s", fileName);
    strcpy(output + outputPtr, fileName);
    outputPtr += strlen(fileName);
    *(output + outputPtr) = '\n';
    outputPtr++;

    char *argument = malloc(1024 * sizeof(*argument));
    char *tmp = malloc(1024 * sizeof(*tmp));
    while (scanf("%s", argument) != EOF) {
        if (*argument == '-') {
            int valid = 0;
            for (int i = 1; i <= rulesCount; i++) {
                if ((*(rules+i)).c == *(argument + 1)) {
                    if (!(*(rules+i)).isArg) {
                        *(output + outputPtr) = (*(rules+i)).c;
                        outputPtr++;
                        *(output + outputPtr) = '\n';
                        outputPtr++;
                    } else {
                        if (scanf("%s", tmp) == EOF) {
                            printf("%s: option requires an argument -- '%c'\n", fileName, *(argument + 1));
                            return 0;
                        }
                        *(output + outputPtr) = (*(rules+i)).c;
                        outputPtr++;
                        *(output + outputPtr) = '=';
                        outputPtr++;
                        strcpy(output + outputPtr, tmp);
                        outputPtr += strlen(tmp);
                        *(output + outputPtr) = '\n';
                        outputPtr++;
                    }
                    valid = 1;
                }
            }
            if (!valid) {
                printf("%s: invalid option -- '%c'\n", fileName, *(argument + 1));
                return 0;
            }
        }
    }
    while (*(output + outputPtr) == '\n' || *(output + outputPtr) == 0) {
        *(output + outputPtr) = 0;
        outputPtr--;
    }
    print(output);
    return 0;
}