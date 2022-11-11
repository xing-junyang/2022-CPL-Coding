#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=5000;i++){
        if((i+1)*i/2<n){
            continue;
        }
        printf("%d/%d",i&1?(i+1-(n-(i-1)*i/2)):(n-(i-1)*i/2),!(i&1)?(i+1-(n-(i-1)*i/2)):(n-(i-1)*i/2));
        return 0;
    }
}