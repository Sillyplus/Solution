#include <iostream>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    int mx = 0, k, t;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        t = k / m;
        if (k % m) t++;
        if (t >= mx) {
            mx = t;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}
