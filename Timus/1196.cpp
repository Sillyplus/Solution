#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 1e5;

int f[MN][3];

int main() {
    int n, m, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (f[x % MN][0]) {
            f[x % MN][2] = x;
        } else {
            f[x % MN][0]++;
            f[x % MN][1] = x;
        }
    }
    int ans = 0;
    cin >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        if (f[x % MN][1] == x || f[x % MN][2] == x) ans++;
    }
    cout << ans << endl;
    return 0;
}
