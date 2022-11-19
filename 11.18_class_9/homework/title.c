#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main() {
    char *str = malloc(5000 * sizeof(*str));
    gets(str);
    int len = strlen(str);
    *(str)=toupper(*(str));
    for (int i = 1; i < len; i++) {
        if (*(str + i) == ' ') {
            *(str + i + 1) = toupper(*(str + i + 1));
        }else if(*(str+i-1)!=' '){
            *(str + i) = tolower(*(str + i));
        }
    }
    puts(str);
    free(str);
    return 0;
}