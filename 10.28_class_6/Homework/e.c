#include <stdio.h>

int a[2005];

int minn(int a,int b){return a<b?a:b;}
void swap(int *a,int *b){
    int tmp=*b;
    *b=*a;
    *a=tmp;
    return;
}
void swapArray(int start,int end){
    int b[1000];
    for(int i=start;i<=end;i++){
        b[i]=a[i];
    }
    for(int i=start,j=end;i<=end&&j>=start;i++,j--){
        a[j]=b[i];
    }
    return ;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int flag=n;
    while(a[flag]<a[flag-1]){
        flag--;
    }
    int pk=a[flag-1];
    int minnum=flag;
    for(int i=flag;i<=n;i++){
        if(a[i]>pk){
            if(a[i]<a[minnum]){
                minnum=i;
            }
        }
    }
    swap(&a[flag-1],&a[minnum]);
    swapArray(flag,n);
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
}