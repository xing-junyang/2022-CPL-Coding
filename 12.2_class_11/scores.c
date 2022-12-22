#include <stdio.h>

const int COLS=3;

void print(int (*table)[COLS],int row){
    for(int i=0;i<row;i++){
        for(int j=0;j<COLS;j++){
            printf("%d ",*(table+i)[j]);
        }
        printf("\n");
    }
}

int main(){
    int stu[4][3]={
            {0,10,20},
            {10,20,30},
            {20,30,40},
            {30,40,50}
    };
    print(stu,4);
    return 0;
}