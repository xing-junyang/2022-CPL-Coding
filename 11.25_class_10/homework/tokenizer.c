/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: tokenizer
 File Name: tokenizer.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/11/28
 Brief description of this program: ..
----------------------- END -----------------------
**************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int outputPtr = 0;

bool isReserved(char *str, char **reserved) {
    for (int i = 0; i <= 15; i++) {
        if (!strcmp(str, *(reserved + i))) {
            return true;
        }
    }
    return false;
}

bool isOperator(char *str, char **operator) {
    for (int i = 0; i <= 10; i++) {
        if (!strcmp(str, *(operator + i))) {
            return true;
        }
    }
    return false;
}

bool isInteger(char *str) {
    int i = 0;
    while (*(str + i)) {
        if (!isdigit(*(str + i))) {
            return false;
        }
        i++;
    }
    return true;
}

bool isFloat(char *str) {
    bool flag = 0;
    int i = 0;
    while (*(str + i)) {
        if (*(str + i) == '.') {
            if (flag) {
                return false;
            }
            flag = 1;
            i++;
            continue;
        }
        if (!isdigit(*(str + i))) {
            return false;
        }
        i++;
    }
    return true;
}

bool isVariable(char *str) {
    if (isdigit(*str) || (!((isalpha(*str) || (*str) == '_')))) {
        return false;
    }
    int i = 1;
    while (*(str + i)) {
        if (!((isalpha(*(str + i)) || (*(str + i)) == '_'))) {
            return false;
        }
        i++;
    }
    return true;
}

void process(char *str, int flag, char **reserved, char **operator, char *output) {

    if (!(*str)) {
        return;
    }
    if (!strcmp(str, ";")) {
        return;
    }
    char *target = malloc(4098 * sizeof(*target));
    if (flag) {
        int i = 0;
        while (*(str + i) != ';') {
            *(target + i) = *(str + i);
            i++;
        }
        *(target + i) = 0;
    } else {
        target = str;
    }
    if (isReserved(target, reserved)) {
        strcpy(output + outputPtr, "reserved ");
        outputPtr += 9;
    } else if (isOperator(target, operator)) {
        strcpy(output + outputPtr, "operator ");
        outputPtr += 9;
    } else if (isInteger(target)) {
        strcpy(output + outputPtr, "integer ");
        outputPtr += 8;
    } else if (isFloat(target)) {
        strcpy(output + outputPtr, "float ");
        outputPtr += 6;
    } else if (isVariable(target)) {
        strcpy(output + outputPtr, "variable ");
        outputPtr += 9;
    } else {
        printf("Compile Error");
        exit(0);
    }
    return;
}

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
    freopen("out.txt", "w", stdout);
    char *str = malloc(4098 * sizeof(*str));
    char *output = malloc(10000 * sizeof(*output));
    char **reserved = malloc(20 * sizeof(*reserved));
    char **operator = malloc(20 * sizeof(*operator));

    *(reserved + 0) = "const";
    *(reserved + 1) = "int";
    *(reserved + 2) = "float";
    *(reserved + 3) = "double";
    *(reserved + 4) = "long";
    *(reserved + 5) = "static";
    *(reserved + 6) = "void";
    *(reserved + 7) = "char";
    *(reserved + 8) = "extern";
    *(reserved + 9) = "return";
    *(reserved + 10) = "break";
    *(reserved + 11) = "enum";
    *(reserved + 12) = "struct";
    *(reserved + 13) = "typedef";
    *(reserved + 14) = "union";
    *(reserved + 15) = "goto";

    *(operator + 0) = "+";
    *(operator + 1) = "-";
    *(operator + 2) = "*";
    *(operator + 3) = "/";
    *(operator + 4) = "=";
    *(operator + 5) = "==";
    *(operator + 6) = "!=";
    *(operator + 7) = ">=";
    *(operator + 8) = "<=";
    *(operator + 9) = ">";
    *(operator + 10) = "<";

    while (scanf("%s", str) != EOF) {
        char *position = strchr(str, ';');
        if (position == NULL) {
            process(str, 0, reserved, operator, output);
        } else {
            process(str, 1, reserved, operator, output);
            strcpy(output + outputPtr, "\n");
            outputPtr++;
            process(position + 1, 0, reserved, operator, output);
        }
    }
    while (*(output + outputPtr) == '\n' || *(output + outputPtr) == 0) {
        *(output + outputPtr) = 0;
        outputPtr--;
    }

    print(output);

    free(str);
    free(operator);
    free(reserved);
    free(output);
    return 0;
}