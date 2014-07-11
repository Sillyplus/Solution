#include <iostream>
#include <cstring>

using namespace std;

int f[100] = {0}, n, ans = 0;

void sol(int k, int a, int b, int c) {
    if (k == 0) return;
    if (f[k] == c) {
        ans = -1;
        return;
    } else if (f[k] == b) {
        ans += 1 << (k-1);
        sol(k-1, c, b, a);
    } else sol(k-1, a, c, b);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> f[i];
    sol(n, 1, 2, 3);
    cout << ans << endl;
    return 0;
}
