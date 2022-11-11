#include <stdio.h>

int notPrime[10000];

void workPrime(int n){
    for(int i=2;i<=n;i++){
        if(notPrime[i]){
            continue;
        }
        for(int j=2;j*i<=n;j++){
            notPrime[j*i]=1;
        }
    }
    notPrime[1]=1;
    return;
}

int numRevs(int input){
    int digit[10];
    int cnt=0;
    while(input){
        digit[++cnt]=input%10;
        input/=10;
    }
    int ans=0;
    for(int i=1;i<=cnt;i++){
        ans+=digit[i];
        ans*=10;
    }
    ans/=10;
    return ans;
}

int main(){
    int n;
   // printf("%d", numRevs(3));
    scanf("%d",&n);
    workPrime(5000);
    int ans=0;
    for(int i=2;i<=n;i++){
        if((!notPrime[i])&&(!notPrime[numRevs(i)])){
            ans++;
        }
    }
    printf("%d",ans);
}