#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MN = 110;

double a[MN];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        double f = 0.0, p = 1.0;
        for (int j = i; j < n; j++) {
            f = f * (1 - a[j]) + p * a[j];
            p *= (1 - a[j]);
        }
        if (f > ans)
            ans = f;
    }
    printf("%.12f\n", ans);
    return 0;
}
