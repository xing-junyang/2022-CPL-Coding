/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: Gym's chemical problem
 File Name: gym_chemical_problem.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/12/22
 Brief description of this program: To solve Gym's chemical problem
----------------------- END -----------------------
**************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct ion {
    char *name;
    char *printName;
    int chargeNumber;
    int isSediment[2];
    enum {
        Cl, Br, NO3, CO3, SO4, OH
    } negIon;
    enum {
        Na, K, Mg, Ca, Ba, Cu, Al, H
    } posIon;
} Ion;

Ion negIon[6] = {{"Cl","Cl", 1},
                 {"Br","Br", 1},
                 {"NO","NO3", 1},
                 {"CO","CO3", 2},
                 {"SO","SO4", 2},
                 {"OH","OH", 1}};
Ion posIon[8] = {{"Na", "Na",1, {-1,  -1}},
                 {"K","K",  1, {-1,  -1}},
                 {"Mg","Mg", 2, {CO3, OH}},
                 {"Ca","Ca", 2, {CO3, -1}},
                 {"Ba","Ba", 2, {CO3, SO4}},
                 {"Cu","Cu", 2, {CO3, OH}},
                 {"Al","Al", 3, {CO3, OH}},
                 {"H","H",  1}};

typedef struct compound {
    int pos;
    int neg;
    bool isSediment;
} Compound;

int gcd(int a, int b) {
    if (!b) { return a; }
    return gcd(b, a % b);
}

void evalSediment(Compound *src) {
    src->isSediment = 0;
    for (int i = 0; i < 2; i++) {
        if (posIon[src->pos].isSediment[i] == src->neg) {
            src->isSediment = 1;
            return;
        }
    }
}

Compound analyzeCompound(const char *src) {
    Compound ret;
    char tmp[10] = {0};
    char *posName = malloc(5 * sizeof(*posName));
    char *negName = malloc(5 * sizeof(*negName));
    int tmpLen = 0;
    int len = strlen(src);
    for (int i = 0; i < len; i++) {
        if (isalpha(src[i])) {
            tmp[tmpLen++] = src[i];
        }
    }
    strcpy(posName, tmp);
    strcpy(negName, tmp);
    if (tmp[0] == 'K' || tmp[0] == 'H') {
        posName[1] = 0;
        negName += 1;
    } else {
        posName[2] = 0;
        negName += 2;
    }
    for (int i = 0; i < 8; i++) {
        if (!strcmp(posIon[i].name, posName)) {
            ret.pos = i;
        }
    }
    for (int i = 0; i < 6; i++) {
        if (!strcmp(negIon[i].name, negName)) {
            ret.neg = i;
        }
    }
    return ret;
}

void compoundSwap(Compound *a, Compound *b) {
    int tmp = a->pos;
    a->pos = b->pos;
    b->pos = tmp;
    tmp = a->neg;
    a->neg = b->neg;
    b->neg = tmp;
    evalSediment(a);
    evalSediment(b);
}

void printCompound(const Compound *src) {
    if (src->pos == H && src->neg == OH) {
        printf("H2O");
        return;
    }
    if (src->pos == H && src->neg == CO3) {
        printf("H2O+CO2↑");
        return;
    }
    int posNum = negIon[src->neg].chargeNumber / gcd(posIon[src->pos].chargeNumber, negIon[src->neg].chargeNumber);
    int negNum = posIon[src->pos].chargeNumber / gcd(posIon[src->pos].chargeNumber, negIon[src->neg].chargeNumber);
    if((src->neg==CO3||src->neg==NO3||src->neg==SO4||src->neg==OH)&&negNum>1){

        //TODO: Print compound with brackets;
    }else{
        //TODO: Print compound without brackets;
    }
    if(src->isSediment){
        printf("↓");
    }
}

int main() {
    char str1[100], str2[100];
    int n;
    scanf("%d", &n);
    getchar();
    for (int k = 1; k <= n; k++) {
        scanf("%99s%99s", str1, str2);
        printf("%s%s==", str1, str2);
//        printf("%s,%s,", posIon[analyzeCompound(str1).pos].name,negIon[analyzeCompound(str1).neg].name);
//        printf("%s,%s\n", posIon[analyzeCompound(str2).pos].name,negIon[analyzeCompound(str2).neg].name);
    }
    return 0;
}