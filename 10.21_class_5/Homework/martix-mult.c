    #include <stdio.h>

    int main(){
        int m,n,p;
        scanf("%d%d%d",&m,&n,&p);
        int a[200][200],b[200][200];
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=p;j++){
                scanf("%d",&b[i][j]);
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=p;j++){
                int ans=0;
                for(int k=1;k<=n;k++){
                    ans+=a[i][k]*b[k][j];
                }
                printf("%d ",ans);
            }
            printf("\n");
        }
    }