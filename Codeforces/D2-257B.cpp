#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int x, y, n;

int main() {
    cin >> x >> y;
    cin >> n;
    int ans;
    n = n % 6;
    switch (n) {
        case 0:
            ans = x-y;
            break;
        case 1:
            ans = x;
            break;
        case 2:
            ans = y;
            break;
        case 3:
            ans = y-x;
            break;
        case 4:
            ans = -x;
            break;
        case 5:
            ans = -y;
            break;
    }
    ans %= 1000000007;
    if (ans < 0)
        ans += 1000000007;
    cout << ans << endl;
    return 0;
}
