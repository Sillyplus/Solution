#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long LL;

const int MN = 30010;

LL n, s;
LL f[MN];
LL sum[MN];
int q[MN];

double grad(int j, int k) {
    return ((f[k]-f[j])*1.0 / (sum[k]-sum[j]));
}

int main() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &sum[i]);
        sum[i] += sum[i-1];
    }
    int h = 1, t = 1;
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        while ((h < t) && (grad(q[h], q[h+1]) <= i)) ++h;
        f[i] = f[q[h]] + (sum[i]-sum[q[h]])*i + (n-i)*s;
        while ((h < t) && (grad(q[t-1], q[t]) >= grad(q[t], i))) --t;
        q[++t] = i;
    }
    cout << f[n] << endl;
    return 0;
}
