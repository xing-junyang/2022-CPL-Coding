/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: game of life
 File Name: game-of-life.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/21
 Brief description of this program:a simple version of game of life
----------------------- END -----------------------
**************************************************/
#include <stdio.h>
#include <unistd.h>

const int SIZE=6;

int board[SIZE][SIZE];
int oldBoard[SIZE][SIZE],newBoard[SIZE][SIZE];
const int direction[3]={-1,0,1};

int getSurviveNumber(int x,int y){
    int counter=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==1&&j==1){
                continue;
            }
            if(x+direction[i]>=SIZE||x+direction[i]<0){
                continue;
            }
            if(y+direction[j]>=SIZE||y+direction[j]<0){
                continue;
            }
            if(board[x+direction[i]][y+direction[j]]){
                counter++;
            }
        }
    }
    return counter;
}

void copyBoard(int *oldBoard,int *newBoard){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            *(newBoard+i*SIZE+j)=*(oldBoard+i*SIZE+j);
        }
    }
    return;
}

void printBoard(int *targetBoard){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            printf("%c ",*(targetBoard+i*SIZE+j)?'*':'~');
        }
        printf("\n");
    }
    printf("\n");
    return;
}

int main(){
    int times;
    scanf("%d",&times);
    board[1][1]=1;board[1][2]=1;board[2][1]=1;board[2][2]=1;
    board[3][3]=1;board[3][4]=1;board[4][3]=1;board[4][4]=1;
    printBoard(board[0]);
    copyBoard(board[0],oldBoard[0]);
    for(int i=1;i<=times;i++){
        copyBoard(oldBoard[0],newBoard[0]);
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                if(oldBoard[i][j]){
                    newBoard[i][j]=(getSurviveNumber(i,j)==2||getSurviveNumber(i,j)==3);
                }else{
                    newBoard[i][j]=(getSurviveNumber(i,j)==3);
                }
            }
        }
        printBoard(newBoard[0]);
        sleep(1);
    }

    return 0;
}