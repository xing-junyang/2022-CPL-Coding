#include <stdio.h>

char board[5000],oldBoard[5000],newBoard[5000];
int n,len=0;

void copyBoard(char* old,char* new){
    for(int i=1;i<=len;i++){
        new[i]=old[i];
    }
    return ;
}

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}

int main(){
    //freopen("a.in","r",stdin);
   // freopen("a.out","w",stdout);
    scanf("%d",&n);
    getchar();
    while((board[++len]=getchar())!=EOF){
        //printf("%d ",len);
    }
    //printf("%d",len);
    len--;
    copyBoard(board,oldBoard);
    for(int times=1;times<=n;times++){
        copyBoard(oldBoard,newBoard);
        for(int i=1;i<=len;i++){
            int aNum=0,bNum=0,dotNum=0;
            for(int j=max(1,i-3);j<=min(i+3,len);j++){
                if(j==i){
                    continue;
                }
                if(oldBoard[j]=='A'){
                    aNum++;
                }
                if(oldBoard[j]=='B'){
                    bNum++;
                }
                if(oldBoard[j]=='.'){
                    dotNum++;
                }
            }
            if(oldBoard[i]=='.'){
                if(aNum==0&&(bNum>=2)&&bNum<=4){
                    newBoard[i]='B';
                }
                if(bNum==0&&(aNum>=2)&&aNum<=4){
                    newBoard[i]='A';
                }
            }
            if(oldBoard[i]=='A'){
                if(bNum||aNum>=5||aNum<=1){
                    newBoard[i]='.';
                }
            }
            if(oldBoard[i]=='B'){
                if(aNum||bNum>=5||bNum<=1){
                    newBoard[i]='.';
                }
            }
        }
        copyBoard(newBoard,oldBoard);
    }
    for(int i=1;i<=len;i++){
        putchar(oldBoard[i]);
    }
    return 0;
}