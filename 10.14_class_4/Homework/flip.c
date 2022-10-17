#include <stdio.h>

int seq[2001];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j*i<=2000;j++){
            seq[j*i]=(seq[j*i]?0:1);
        }
    }
    for(int i=1;i<=n;i++){
        if(seq[i]){
            printf("%d ",i);
        }
    }
    return 0;
}