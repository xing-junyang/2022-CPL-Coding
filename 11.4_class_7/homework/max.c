#include <stdio.h>

int a[100005];
int ans[100005][2];

void work(int l,int r){
    if(l==r){
        ans[l][0]=l;
        ans[l][1]=l;
        return;
    }
    int max=l;
    for(int i=l+1;i<=r;i++){
        if(a[i]>a[max]){
            max=i;
        }
    }
    ans[max][0]=l,ans[max][1]=r;
    if(max!=l){
        work(l,max-1);
    }
    if(max!=r){
        work(max+1,r);
    }

    return;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    work(1,n);
    for(int i=1;i<=n;i++){
        printf("%d %d\n",ans[i][0],ans[i][1]);
    }
    return 0;
}