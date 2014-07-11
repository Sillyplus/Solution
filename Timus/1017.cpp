#include <iostream>

using namespace std;

const int MN = 510;

long long f[MN][MN] = {0};

int main() {
    int n;
    cin >> n;
    f[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            f[i][j] = f[i-1][j-1] + f[i-j][j-1];
        }
    }
    long long ans = 0;
    for (int i = 1; i < n; i++)
        ans += f[n][i];
    cout << ans << endl;
    return 0;
}
