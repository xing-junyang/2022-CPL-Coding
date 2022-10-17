#include <stdio.h>

int a[1000005];
int n, k;

void swap(int *a, int *b) {
    int tmp;
    tmp = *b;
    *b = *a;
    *a = tmp;
    return;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int mid = a[k];
    int l = 1, r = n;
    while (l != r) {
        while (a[l] < mid && (l != r)) {
            l++;
        }
        while (a[r] >= mid && (l != r)) {
            r--;
        }
        if (l != r) {
            if (l == k) {
                k = r;
            }
            swap(&a[l], &a[r]);
        }
    }
    //printf("%d\n%d\n",r,k);
    if (r < k) {
        swap(&a[r], &a[k]);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }

}