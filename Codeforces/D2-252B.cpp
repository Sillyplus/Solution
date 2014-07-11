#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

const int MN = 3010;

int n, v;
int f[MN] = {0};

int main() {
    cin >> n >> v;
    int a, b;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        f[a] += b;
    }
    int ans = 0;
    for (int i = 1; i <= 3001; i++) {
        if (f[i]+f[i-1] <= v) {
            ans += (f[i]+f[i-1]);
            f[i] = 0;
        } else {
            ans += v;
            f[i] = f[i] - max(v - f[i-1], 0);
        }
    }
    cout << ans << endl;
    return 0;
}
