#include <iostream>

using namespace std;

const int MN = 100;

int n, m;
int f[MN];

int fa(int x) {
    return f[x] = f[x] == x ? x : fa(f[x]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        f[fa(x)] = fa(y);
    }
    long long ans = 1LL << n;
    for (int i = 1; i <= n; i++)
        if (fa(f[i]) == i) {
            ans /= 2;
        }
    cout << ans << endl;
    return 0;
}
