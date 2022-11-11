#include <stdio.h>

int main(){
    int n;
    int f[101]={0,1,1};
    for(int i=3;i<=100;i++){
        f[i]=f[i-1]+f[i-2];
    }
    scanf("%d",&n);
    printf("%d",f[n+1]);
    return 0;
}