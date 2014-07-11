#include <iostream>
#include <cmath>

using namespace std;

long long n, m;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    cin >> n >> m;
    long long x;
    int ans = 0;
    if (m % n != 0) {
        ans = 0;
    } else {
        x = m / n;
        for (int i = 1; i <= sqrt(x); i++)
            if (x % i == 0)
                if (gcd(i, x/i) == 1)
                    ans++;
    }
    cout << ans << endl;
    return 0;
}
