#include <stdio.h>

int main(){
    int n,t;
    scanf("%d%d",&n,&t);
    int ans=0;
    for(int i=1;i<=n;i++){
        int tmp=t;
        for(int j=1;j<i;j++){
            tmp*=10;
            tmp+=t;
        }
        ans+=tmp;
    }
    printf("%d",ans);
}