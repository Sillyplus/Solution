#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

const int MD = 1e9 + 9;

int n;
bool prim[10][10][10];
int f[10010][10][10];

bool isPrim(int x) {
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;
    return true;
}

int main() {
    memset(prim, false, sizeof(prim));
    memset(f, 0, sizeof(f));
    for (int i = 100; i < 1000; i++)
        if (isPrim(i)) {
            prim[i/100][i%100/10][i%10] = true;
            f[3][i%100/10][i%10]++;
        }
    cin >> n;
    for (int i = 4; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                for (int x = 0; x < 10; x++) {
                    if (prim[j][k][x]) {
                        f[i][k][x] += f[i-1][j][k];
                        f[i][k][x] %= MD;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            ans += f[n][i][j];
            ans %= MD;
        }
    }
    cout << ans << endl;
    return 0;
}
