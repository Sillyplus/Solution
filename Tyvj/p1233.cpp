#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MN = 1010;

int n, ans;
int a[MN];
int f[MN][MN];

bool ck(int x, int y) {
    return x == y;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            f[i][j] = max(f[i-1][j-1], f[i-1][j] + ck(a[i], i-j));
        }
    }
    ans = 0;
    for (int i = 0; i <= n; i++)
        ans = max(ans, f[n][i]);
    cout << ans << endl;
    return 0;
}
