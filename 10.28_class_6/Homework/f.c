#include <stdio.h>

int board[1005][1005];
int n;

int bao(int x){
    if(x>n){
        return 1;
    }
    if(x<1){
        return n;
    }
    return x;
}

void putNextNumber(int x,int y,int num){
    if(num>n*n){
        return;
    }
    if(board[bao(x-1)][bao(y+1)]){
        board[bao(x+1)][bao(y)]=num;
        putNextNumber(bao(x+1),bao(y),num+1);
    }else{
        board[bao(x-1)][bao(y+1)]=num;
        putNextNumber(bao(x-1),bao(y+1),num+1);
    }
}

int main(){
    //freopen("a.out","w",stdout);
    scanf("%d",&n);
    board[1][n/2+1]=1;
    putNextNumber(1,n/2+1,2);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}