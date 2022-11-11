#include <stdio.h>

long long pascal[100][100];

void work(){
    pascal[1][1]=1;
    pascal[2][1]=1;
    pascal[2][2]=1;
    for(int i=3;i<=36;i++){
        for(int j=2;j<=i-1;j++){
            pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
        }
        pascal[i][1]=pascal[i][i]=1;
    }
}

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    work();
    printf("%lld",pascal[a][b]);
    return 0;
}