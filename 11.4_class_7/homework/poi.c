#include <stdio.h>

int f[100005];

int find(int x){
    if(x==f[x]){
        return x;
    }else{
        f[x]=find(f[x]);
        return f[x];
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&f[i]);
    }
    for(int i=1;i<=n;i++){
        f[i]= find(i);
        printf("%d ",f[i]);
    }

    return 0;
}