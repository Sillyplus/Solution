#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

const int MN = 2010;

int n, x;
int t[MN], h[MN], m[MN];
bool vit[MN];

int sol(int tt) {
    int ret = 0;
    int sh = x;
    memset(vit, 0, sizeof(vit));
    while (1) {
        int flag = -1;
        for (int i = 0; i < n; i++) {
            if (sh >= h[i] && t[i] == tt && !vit[i]) {
                if (flag < 0 || m[i] > m[flag])
                    flag = i;
            }
        }
        if (flag < 0) break;
        sh += m[flag];
        vit[flag] = true;
        ret++;
        tt ^= 1;
    }
    return ret;
}

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> h[i] >> m[i];
    }
    int ans = 0;
    ans = max(sol(0), sol(1));
    cout << ans << endl;
    return 0;
}
