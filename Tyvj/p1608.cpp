#include <iostream>
#include <cmath>

using namespace std;

const int MN = 210;
const int dv = 400;

int n, m;
int a[MN], b[MN];
int f[MN][40][MN<<2];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    for (int i = 0; i < MN; i++)
        for (int j = 0; j < 40; j++)
            for (int k = 0; k < MN<<2; k++)
                f[i][j][k] = -1;
    f[1][1][a[1]-b[1]+dv] = a[1]+b[1];
    f[1][0][dv] = 0;
    for (int i = 2; i <= n; i++) {
        f[i][0][dv] = 0;
        for (int j = 1; j <= min(m, i); j++) {
            for (int k = -dv; k <= dv; k++)
                if (f[i-1][j-1][k-(a[i]-b[i])+dv] != -1)
                    f[i][j][k+dv] = max(f[i-1][j][k+dv], f[i-1][j-1][k-(a[i]-b[i])+dv]+(a[i]+b[i]));
                else
                    f[i][j][k+dv] = f[i-1][j][k+dv];
        }
    }
    for (int i = 0; i <= dv; i++)
        if ((f[n][m][i+dv] >= 0) || (f[n][m][dv-i] >= 0)) {
            cout << i << endl;
            cout << max(f[n][m][i+dv], f[n][m][dv-i]) << endl;
            break;
        }
    return 0;
}
