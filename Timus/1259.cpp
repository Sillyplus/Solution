#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n/2; i++)
        if (gcd(n, i) == 1) ans++;
    cout << ans << endl;
    return 0;
}
