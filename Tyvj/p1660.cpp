#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MN = 10010;

int n, k;
int a[MN];
double sum;

bool cmp(const int a, const int b) {
    return a > b;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a+n, cmp);
    for (int i = 0; i < n; i++)
        sum += (a[i] * (i+1));
    sum /= n;
    printf("%.2f\n", sum);
    sum = 0;
    for (int i = 0; i <= n/k; i++) {
        for (int j = 0; j < k; j++) {
            sum += (a[i*k+j] * (i+1));
            if ((i*k+j) == n) break;
        }
    }
    sum /= n;
    printf("%.2f\n", sum);
    return 0;
}
