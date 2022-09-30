/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: A (Naive) Administration System
 File Name: AAdminSystem.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/9/30
 Brief description of this program: ..
----------------------- END -----------------------
**************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

struct Data{
    char *firstName;
    char *lastName;
    bool gender; //0 for male, 1 for female;
    int birthday[3]; //yyyy/mm/dd
    char *weekday;
    int birthYear,birthMonth,birthDay;
    int cScore,musicScore,medicineScore;
    double mean,sd;
};

int main(){
    struct Data Luodayou;
    Luodayou.firstName="Tayu";
    char firstName[]="Tayu";
    char lastName[]="Lo";
    char gender='n';
    int birthYear=1954;
    int birthMonth=20;
    int birthDay=7;
    char weekday[]="Tuesday";
    int cScore=50;
    int musicScore=99;
    int medicineScore=70;
    double mean=(cScore+musicScore+medicineScore)/3.0;
    double sd= sqrt(pow(cScore-mean,2)+pow(musicScore-mean,2)+ pow(medicineScore-mean,2)/3.0);
    int rank= 10;

    printf("%s %s \t %c\n",firstName,lastName, toupper(gender));
    printf("%.2d/%d/%d \t %.3s \n",birthDay,birthMonth,birthYear,weekday);
    printf("%d\t%d\t%d\t\n",cScore,musicScore,medicineScore);
    printf("%.1lf\t%.2lf\t%d%%\n",mean,sd,rank);

    return 0;
}