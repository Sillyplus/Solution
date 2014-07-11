#include <iostream>

using namespace std;

const int MD = 1000007;

int n, m;
int f[110][110];
int a[110];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= a[1]; i++)
        f[1][i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= a[i]; k++) {
                if (j-k >= 0) {
                    f[i][j] = (f[i][j] + f[i-1][j-k]) % MD;
                } else {
                    break;
                }
            }
    cout << f[n][m] << endl;
    return 0;
}
