/**************************************************
--------------- PROGRAM INFORMATION ---------------
 Project Name: factorial
 File Name: factorial.c
 Author: xingjunyang
 Email: xingjunyang@smail.nju.edu.cn
 Date of Creation: 2022/10/7
 Brief description of this program:
----------------------- END -----------------------
**************************************************/
#include <stdio.h>

const int mod=10007;

int main() {
    int n;
    scanf("%d",&n);
    long long ans=1;
    for(int i=n;i>1;--i){
        ans=(ans*i)%mod;
        ans++;
    }
    printf("%lld",ans);
    return 0;
}
