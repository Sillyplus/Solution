#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 2010;
const int MAXM = 510;

int f[MAXN][MAXM];
int d[MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
    }
    for (int i = 1; i <= n; i++) {
        f[i][0] = max(f[i-1][0], f[i][0]);
        for (int j = 1; j <= m; j++) {
            f[i][j] = f[i-1][j-1] + d[i];
            if (i >= j) f[i][0] = max(f[i][0], f[i-j][j]);
            f[i][0] = max(f[i-1][0], f[i][0]);
        }
    }
    cout << f[n][0] << endl;
    return 0;
}
