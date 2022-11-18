#include <stdio.h>
#include <stdlib.h>

/*
 * define dynamic array
 * eg, int *ptr = malloc(len * sizeof(*ptr)), len for the length of array.
 * after using the array, the space must be freed.
 * eg, free(ptr);
 * you cannot free a space that is not defined by malloc.
 * the function of malloc and free is in the library <stdlib.h>.
 *
 * the name of an array is not a variable.
 *
 *
 */

int main() {
    int len;
    scanf("%d", &len);
    int *ptr = malloc(len * sizeof(*ptr));
    if (ptr == NULL) {
        return 0;
    }
    free(ptr);
    return 0;
}