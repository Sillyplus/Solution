#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MD = 20123;
const int MN = 10010;

int n, m;
int a[MN];
int mp[MN][110];
bool v[MN][110];

int main() {
    cin >> n >> m;
    int k, x, t;
    memset(v, false, sizeof(v));
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d%d", &k, &x);
            mp[i][j] = x;
            v[i][j] = k;
            a[i] += k;
        }
    }
    cin >> x;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        t = mp[i][x] % a[i];
        if (t == 0) t = a[i];
        ans = (ans + mp[i][x]) % MD;
        if (v[i][x]) t--;
        while (t != 0) {
            x = (x+1) % m;
            if (v[i][x])
                t--;
        }
    }
    cout << ans << endl;
    return 0;
}
