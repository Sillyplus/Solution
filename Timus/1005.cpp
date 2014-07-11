#include <iostream>
#include <cmath>

using namespace std;

int a[22] = {0};

int main() {
    int n, s = 0, ans;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }
    ans = s;
    int tmp, ts, k, x;
    for (int i = 0; i < (1 << n); i++) {
        tmp = i;
        ts = 0;
        x = 0;
        while (tmp) {
            x++;
            if (tmp % 2) ts += a[x];
            tmp /= 2;
        }
        k = abs(s-ts - ts);
        if (k < ans) ans = k;
    }
    cout << ans << endl;
    return 0;
}
