#include <stdio.h>
#include <math.h>

int n, a[21], p;

double abss(double x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

double fx(double x) {
    double ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += a[i] * pow(x, i);
    }
    return pow(ans, p);
}

double simpsonFormula(double l, double r) {
    double ans;
    ans = (4 * fx((l + r) / 2) + fx(l) + fx(r)) * (r - l) / 6;
    return ans;
}

double calc(double l, double r, double eps) {
    double SL, SR, S;
    double mid = (l + r) / 2;
    SL = simpsonFormula(l, mid);
    SR = simpsonFormula(mid, r);
    S = simpsonFormula(l, r);
    if (abss(SL + SR - S) <= 15 * eps) {
        return SL + SR + (SL + SR - S) / 15;
    } else {
        double LL = calc(l, mid, eps / 2);
        double RR = calc(mid, r, eps / 2);
        return LL + RR;
    }
}

int main() {
    scanf("%d%d", &n, &p);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    double a, b;
    scanf("%lf%lf", &a, &b);
    printf("%lf", calc(a, b, 1e-5));
    return 0;
}