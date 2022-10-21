#include <stdio.h>

const int dire[3]={-1,0,1};

int n;
char board[200][200];

int getMineAmount(int x,int y){
    int cnt=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==1&&j==1){
                continue;
            }
            if(x+dire[i]>n||x+dire[i]<1){
                continue;
            }
            if(y+dire[j]>n||y+dire[j]<1){
                continue;
            }
            if(board[x+dire[i]][y+dire[j]]=='*'){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){

    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%c",&board[i][j]);
        }
        getchar();
    }
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j] == '*') {
                printf("*");
                continue;
            } else {
                board[i][j] = getMineAmount(i, j) + '0';
            }
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}