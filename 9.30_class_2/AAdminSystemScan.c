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
#include <math.h>
#include <ctype.h>

int main() {
    char firstName[] = "Tayu";
    char lastName[] = "Lo";
    char gender = 'n';
    scanf("%s%s %c", firstName, lastName, &gender);
    int birthYear = 1954;
    int birthMonth = 20;
    int birthDay = 7;
    scanf("%d/%d/%d", &birthYear, &birthMonth, &birthDay);
    char weekday[] = "Tuesday";
    int cScore = 50;
    int musicScore = 99;
    int medicineScore = 70;
    scanf("%d%d%d", &cScore, &musicScore, &medicineScore);
    double mean = (cScore + musicScore + medicineScore) / 3.0;
    double sd = sqrt(pow(cScore - mean, 2) + pow(musicScore - mean, 2) + pow(medicineScore - mean, 2) / 3.0);
    int rank = 10;
    scanf("%d%%", &rank);

    printf("%s %s \t %c\n", firstName, lastName, toupper(gender));
    printf("%.2d/%d/%d \t %.3s \n", birthDay, birthMonth, birthYear, weekday);
    printf("%d\t%d\t%d\t\n", cScore, musicScore, medicineScore);
    printf("%.1lf\t%.2lf\t%d%%\n", mean, sd, rank);

    return 0;
}