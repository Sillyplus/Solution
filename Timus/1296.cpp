#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int n, x, ans = 0, f = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        f = max(f + x, x);
        ans = max(ans, f);
    }
    cout << ans << endl;
    return 0;
}
