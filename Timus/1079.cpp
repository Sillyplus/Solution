#include <iostream>
#include <cmath>

using namespace std;

long long f[100010];

int main() {
    int n;
    cin >> n;
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i < 100000; i++) {
        if (i % 2) f[i] = f[i/2] + f[i/2 + 1];
            else f[i] = f[i/2];
    }
    while (n) {
        long long ans = -1;
        for (int i = 0; i <= n; i++)
            ans = max(ans, f[i]);
        cout << ans << endl;
        cin >> n;
    }
    return 0;
}
