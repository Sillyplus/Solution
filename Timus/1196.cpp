#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 1e9 + 1;

bool f[MN] = {0};

int main() {
    int n, m, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        f[x] = true;
    }
    int ans = 0;
    cin >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        if (f[x]) ans++;
    }
    cout << ans << endl;
    return 0;
}
