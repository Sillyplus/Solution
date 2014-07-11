#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double a[110][3];

int main() {
    int n;
    double ans = 0.0, x, y, r;
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][1] >> a[i][2];
    }
    a[0][1] = a[n][1];
    a[0][2] = a[n][2];
    for (int i = 1; i <= n; i++) {
        x = a[i][1]-a[i-1][1];
        y = a[i][2]-a[i-1][2];
        ans += sqrt(x*x + y*y);
    }
    ans += 2.0*(3.141592653)*r;
    printf("%.2f\n", ans);
    return 0;
}
