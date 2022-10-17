#include <stdio.h>

int pow(int x,int y){
    //return x^y
    if(y==0){
        return 1;
    }
    int ans=x;
    for(int i=1;i<=y-1;i++){
        ans*=x;
    }
    return ans;
}

int main(){
    int len,N;
    char str[50];
    scanf("%d%d%*c",&len,&N);
    int val[50];
    for(int i=1;i<=len;i++){
        scanf("%c",&str[i]);
        if(str[i]>='0'&&str[i]<='9'){
            val[i]=str[i]-'0';
        }else{
            val[i]=str[i]-'A'+10;
        }
        if(val[i]>=N){
            printf("Error");
            return 0;
        }
    }
    int ans=0;
    for(int i=1;i<=len;i++){
        ans+=val[i]*pow(N,len-i);
    }
    printf("%d",ans);
}