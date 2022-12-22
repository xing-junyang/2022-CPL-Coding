#include <stdio.h>
#include <math.h>

const int NUM_OF_PARTITION=100000;

double Integrate (double low, double high, double (*fp)(double)){
    double interval = (high - low) / NUM_OF_PARTITION;

    double sum = 0.0;
    for(int i=0;i<NUM_OF_PARTITION;i++){
        double xi = low + interval * i;
        double yi = (*fp)(xi); // is equivalent to yi = fp(xi)
        sum += yi * interval;
    }
    return sum;
}

int main(){
    printf("%lf\n", Integrate(0,1,sin));
    double (*fps[2])(double)={sin,cos};
    for(int i=0;i<2;i++){
        printf("%lf\n", Integrate(0,1,fps[i]));
    }
    return 0;
}