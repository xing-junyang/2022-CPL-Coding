#include <stdio.h>
#include <string.h>

char input[1000005];

int main(){
    gets(input);
    int ans=0;
    for(int i=0;i<strlen(input);i++){
        ans+=input[i]-'0';
    }
    ans%=9;
    printf("%d",ans);
}

/*
 * Q: How much do you love me?
 * A: -1.
 * Q: Why's that?
 * A: My love overflowed.
 */

