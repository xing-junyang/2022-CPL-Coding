#include <stdio.h>

int dead[501];
int n,k;

int main(){
    scanf("%d%d",&n,&k);
    int now=0,left=n;
    while(left){
        for(int i=1;i<=k;i++){
            while(1){
                ++now;
                if(now>n){
                    now=1;
                }
                if(!dead[now]){
                    break;
                }
            }
            if(i==k){
                dead[now]=1;
                left--;
            }
            if(left==0){
                break;
            }
        }
    }
    printf("%d",now);
}