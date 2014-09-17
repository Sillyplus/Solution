#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int ans[5];

int main() {
    int t, n, k, x;
    cin >> t;
    while (t--) {
        memset(ans, 0, sizeof(ans));
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> k >> x;
            if (k == 1)
                ans[1] = max(ans[1], x);
            if (k == 2)
                ans[2] = max(ans[2], x);
            if (k == 3)
                ans[3] = max(ans[3], x);
        }
        for (int i = 1; i <= 3; i++)
            if (ans[i])
                cout << i << ' ' << ans[i] << endl;
    }
    return 0;
}
