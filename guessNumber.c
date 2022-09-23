/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: guessNumber
 File Name: guessNumber.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/9/23
 Brief description of this program: To play guess number game.
----------------------- END -----------------------
**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int high=100;
const int number=7;

int main(){
    srand(time(0));
    int secretNum=(rand()%high)+1;
    int guessTimes=0;
    printf("Let's play the guess the number game!\n"
           "You have %d chances!\n",number);
    while(guessTimes<number){
        guessTimes++;
        printf("Input your guess:(from 1 to %d)",high);
        int userInput;
        scanf("%d",&userInput);
        if(userInput==secretNum){
            printf("You win in %d time(s)!\n",guessTimes);
            return 0;
        }
        if(userInput<secretNum){
            printf("Your guess is less than the number!\n");
        }else{
            printf("Your guess is greater than the number\n");
        }
        printf("You still have %d chance(s)!\n",number-guessTimes);
    }
    printf("Better luck next time!\n");
    printf("Written by xjy\n");
    return 0;
}