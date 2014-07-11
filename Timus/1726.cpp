#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int MN = 100010;

long long x[MN], y[MN];
long long n;

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        scanf("%lld%lld", &x[i], &y[i]);
    }
    sort(x, x+n);
    sort(y, y+n);
    long long ans = 0;
    for (long long i = 0; i < n-1; i++) {
        ans += (x[i+1] - x[i] + y[i+1] - y[i]) * (i+1) * (n - i-1) * 2;
    }
    ans /= (n*(n-1));
    cout << ans << endl;
    return 0;
}
