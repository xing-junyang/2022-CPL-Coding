#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *str1= malloc(100005* sizeof(*str1));
    char *str2= malloc(100005* sizeof(*str2));
    int *show=malloc(100005* sizeof(*show));
    memset(show,0, sizeof(*show));
    gets(str1);
    int str1Len=strlen(str1);
    gets(str2);
    int str2Len= strlen(str2);
    int nowCmp=0;
    for(int i=0;i<str1Len;i++){
        if(i+str2Len>str1Len){
            break;
        }
        for(int j=0;j<str2Len;j++){
            if(*(str1+i+j)!=*(str2+j)){
                break;
            }
            if(j==str2Len-1){
                *(show+(++nowCmp))=i;
            }
        }
    }
    for(int i=1;i<=nowCmp;i++){
        printf("%d ",*(show+i));
    }
    return 0;
}