#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const int MN = 1010;

bool map[MN][MN] = {0};
double f[MN][MN] = {0};

int main() {
    int n, m;
    cin >> m >> n;
    int t, x, y;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> y >> x;
        map[x][y] = true;
    }
    double k = sqrt(2.0) * 100;
    for (int i = 1; i <= n; i++) f[i][0] = i*100;
    for (int i = 1; i <= m; i++) f[0][i] = i*100;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = min(f[i-1][j], f[i][j-1]) + 100;
            if (map[i][j]) {
                f[i][j] = min(f[i][j], f[i-1][j-1] + k);
            }
        }
    }
    printf("%.0f\n", f[n][m]);
    return 0;
}
