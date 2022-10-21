#include <stdio.h>
#include <string.h>

int board[9][9];
int judge[10];

int ju(){
    for(int i=1;i<=9;i++){
        if(judge[i]!=1){
            return 0;
        }
    }
    return 1;
}

int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%d",&board[i][j]);
            if(board[i][j]>9||board[i][j]<=0){
                printf("NO");
                return 0;
            }
        }
    }
    for(int i=0;i<9;i++){
        memset(judge,0,sizeof judge);
        for(int j=0;j<9;j++){
           judge[board[i][j]]++;
        }
        if(!ju()){
            printf("NO");
            return 0;
        }
    }
    for(int i=0;i<9;i++){
        memset(judge,0,sizeof judge);
        for(int j=0;j<9;j++){
            judge[board[j][i]]++;
        }
        if(!ju()){
            printf("NO");
            return 0;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            memset(judge,0,sizeof judge);
            for(int m=0;m<3;m++){
                for(int n=0;n<3;n++){
                    judge[board[i*3+m][j*3+n]]++;
                }
            }
            if(!ju()){
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");

    return 0;
}