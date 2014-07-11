#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

const int MN = 300010;

int n;
int a[MN];
long long f[MN][3];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    f[1][1] = 2147483648;
    f[n][2] = 2147483648;
    f[1][0] = a[1];
    for (int i = 2; i <= n; i++) {
        f[i][0] = min(min(f[i-1][0], f[i-1][1]), f[i-1][2]) + a[i];
        f[i][1] = f[i-1][0];
        if (i != n) {
            f[i][2] = min(f[i-1][1], f[i-1][0]);
        }
    }
    cout << min(min(f[n][0], f[n][1]), f[n][2]) << endl;
    return 0;
}
