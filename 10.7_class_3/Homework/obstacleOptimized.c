/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: obstacle optimized
 File Name: obstacleOptimized.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/10
 Brief description of this program: Optimized algorithm of obstacle.c
----------------------- END -----------------------
**************************************************/
#include <stdio.h>

struct Point{
    int x,y;
};

int sgn(int x){//x>0->1;x=0->0;x<0->-1
    if(!x){
        return 0;
    }
    return x>0?1:-1;
}

void whereAreWeGoing(struct Point *nowPos,struct Point destinationPos){
    int flag=sgn(nowPos->x-destinationPos.x)*3+sgn(nowPos->y-destinationPos.y);

}

int main(){

    return 0;
}