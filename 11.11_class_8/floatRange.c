/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: float range
 File Name: floatRange.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/11/11
 Brief description of this program: show range of float and double
----------------------- END -----------------------
**************************************************/
#include <stdio.h>
#include <float.h>

int main(){
    printf("FLT_MAX:%e\n",FLT_MAX);
    printf("FLT_MIN:%e\n",FLT_MIN);
    printf("FLT_EPSILON:%e\n",FLT_EPSILON);
    printf("FLT_TRUE_MIN:%e\n",FLT_TRUE_MIN);
    printf("\n");
    printf("DBL_MAX:%e\n",DBL_MAX);
    printf("DBL_MIN:%e\n",DBL_MIN);
    printf("DBL_EPSILON:%e\n",DBL_EPSILON);
    printf("DBL_TRUE_MIN:%e\n",DBL_TRUE_MIN);

    return 0;
}