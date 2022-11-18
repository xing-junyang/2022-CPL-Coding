#include <stdio.h>
#include <memory.h>
#define size 100002
int a[2*size+1]={0};
int store[size]={0};
int storedot[size];

void step(int count0,int b,int c,int d);

int main(){
    freopen("inputOfBuddy.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n = 0,q = 0;
    char num[size];
    memset(num ,' ',sizeof num);
    memset(storedot ,-1,sizeof storedot);
    scanf("%d %d",&n,&q);
    store[0] = 1<<n;
    storedot[0] = 0;

    int m=0;
    for (int i = 1; i < q+1; ++i) {
        getchar();
        scanf("%c",&num[i]);
        if (num[i]=='A'){
            m++;
            scanf("%d %d",&a[2*m-1],&a[2*m]);
        }
    }
    //成功录入数据，并开始处理数据----------------------------------------------------------
    int count1=0;//计算‘A’操作的次数
    for (int i = 1; i < q+1; ++i) {
        int count0=0;
        for (int j = 0; j <size ; ++j) {
            if(store[j]==0){
                break;
            } else{
                count0++;
            }
        }
        if(num[i]=='Q'){
            printf("%d\n",count0);
            for (int k = 0; k < count0; ++k) {
                if(storedot[k] >= 0)
                    printf("%d ",storedot[k]);//---------------------------待解决
            }
            if(i!=q) {
                printf("\n");
            }
        }
        if(num[i]=='A'){
            count1++;
            step(count0,a[2*count1-1],a[2*count1],0);
            //发生改变-----------------------------------------------待解决

        }
    }
    //for (int i = 1; i <100; ++i) {
    //  printf("%c",num[i]);
    //}

    return 0;
}



void step(int count0,int b,int c,int d){
    int i=d;
    for ( i = d; i < count0; ++i) {
        if(c > store[i])continue;
        if(c <= store[i] && storedot[i] > 0 )continue;
        if(c == store[i] && storedot[i]==0){
            storedot[i]=b;
            return;
        }
        if((c < store[i] && c > store[i]/2)){
            storedot[i]=b;
            return;
        }
        if(c <= store[i]/2){
            //存储器的改变
            if(i != count0-1) {
                for (int j = count0; j > i + 1; j--) {
                    store[j] = store[j - 1];
                }
                store[i + 1] = store[i] / 2;
                store[i] = store[i] / 2;
                //节点发生的改变
                for (int j = count0; j > i + 1; j--) {
                    storedot[j] = storedot[j - 1];
                }
                storedot[i + 1] = 0;
                storedot[i] = 0;
            } else {
                store[i+1]=store[i]/2;
                store[i] = store[i]/2;
                storedot[i+1]=0;
                storedot[i]=0;
            }
            break;
        }

    }
    step(count0+1,b,c,i);
}
