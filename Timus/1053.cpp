#include <iostream>

using namespace std;

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main() {
    int n, ans, k;
    cin >> n >> ans;
    n--;
    while (n--) {
        cin >> k;
        ans = gcd(ans, k);
    }
    cout << ans << endl;
    return 0;
}
