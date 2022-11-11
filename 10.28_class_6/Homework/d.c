    #include <stdio.h>

    int toTen(int x,int k){
        int digit[100];
        int cnt=0;
        while(x){
            digit[++cnt]=x%10;
            x/=10;
        }
        int ans=0;
        for(int i=cnt;i>=1;i--){
            if(digit[i]>=k){
                return -1;
            }
            ans+=digit[i];
            ans*=k;
        }
        ans/=k;
        return ans;
    }

    int main(){
        int p,q,r;
        scanf("%d%d%d",&p,&q,&r);
        for(int i=2;i<=40;i++){
            if(toTen(p,i)==-1||toTen(q,i)==-1||toTen(r,i)==-1){
                continue;
            }
            if(toTen(p,i)* toTen(q,i)== toTen(r,i)){
                printf("%d",i);
                return 0;
            }
        }
        printf("0");
        return 0;
    }