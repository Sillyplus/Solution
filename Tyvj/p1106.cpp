#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int MN = 1010;

int n;
int a[MN][MN];
int f[MN][MN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            scanf("%d", &a[i][j]);
    memset(f, 63, sizeof(f));
    f[1][1] = a[1][1];
    for (int i = 2; i <= n; i++) {
        while (1) {
            int flag = 1;
            f[i][0] = f[i][i];
            f[i][i+1] = f[i][1];
            for (int j = 1; j <= i; j++) {
                int k;
                k = min(f[i-1][j-1], min(f[i-1][j], min(f[i][j-1], f[i][j+1])));
                if (f[i][j] > k+a[i][j]) {
                    f[i][j] = k+a[i][j];
                    flag = 0;
                }
            }
            if (flag) break;
        }
    }
    cout << f[n][1] << endl;
    return 0;
}
