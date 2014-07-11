#include <iostream>

using namespace std;

const int MD = 1000000007;
const int MN = 2010;

int n, m;
int f[MN][MN] = {0};
int a[MN][MN] = {0};

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            if (i % j == 0) {
                a[i][0]++;
                a[i][a[i][0]] = j;
            }
    }
    for (int i = 1; i <= n; i++) f[1][i] = 1;
    for (int k = 2; k <= m; k++) {
        for (int i = 1; i <= n; i++) {
            for (int x = 1; x <= a[i][0]; x++)
                f[k][i] = (f[k][i] + f[k-1][a[i][x]]) % MD;
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum = (sum + f[m][i]) % MD;
    }
    cout << sum << endl;
    return 0;
}
