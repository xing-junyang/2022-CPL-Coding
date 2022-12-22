#include <stdio.h>

char **argv;

int *names[10];

int (*music)[10];

int atexit (void (*func)(void));

void (*(signal(int sig, void (*handler)(int))))(int);
void handler(int x);
void signalT();
int sig;

char (*(*func(int num, char *str))[])();

char (*(*arr[3])())[5];

int main(){
    signal(sig,handler);
    (*music)[1]=1;

    return 0;
}