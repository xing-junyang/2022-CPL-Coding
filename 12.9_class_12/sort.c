#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void qsort( void *ptr, size_t count, size_t size,
//            int (*comp)(const void *, const void *) );
//count: amount of elements;
//size: size of a single element;
//

int compareInts(const void *left, const void *right){
    int *leftInt=(int *)left;
    int *rightInt=(int *)right;
    if(*leftInt>*rightInt){
        return 1;
    }
    return -1;
}

int compareStrs(const void *left, const void *right){
    char *const *pp1 = left;
    char *const *pp2 = right;
    return strcmp(*pp1,*pp2);
}

int testInt[5]={1,2,-3,4,3};

int main(){
    qsort(testInt,5, sizeof(int),compareInts);
    for(int i=0;i<5;i++){
        printf("%d ",testInt[i]);
    }
    return 0;
}