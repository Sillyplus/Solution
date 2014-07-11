#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MN = 510;

double a[MN];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    double ans = 0;
    int x, y, v;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &x, &y, &v);
        double k;
        if (v == 0)
            k = 0;
        else
            k = (a[x]+a[y]) / double(v);
        ans = max(ans, k);
    }
    printf("%.15f\n", ans);
    return 0;
}
