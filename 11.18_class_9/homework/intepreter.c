#include <stdio.h>

int main() {
    unsigned int x;
    scanf("%X", &x);
    void *ptr = &x;
    unsigned int *usInt = ptr;
    int *Int = ptr;
    float *Flo = ptr;
    printf("%d\n%u\n%.6f\n%.3e", *Int, *usInt, *Flo, *Flo);
    return 0;
}
