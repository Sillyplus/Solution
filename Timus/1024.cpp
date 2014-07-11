#include <iostream>

using namespace std;

int f[1010] = {0};

long long gcd(long long a, long long b) {
    return (b == 0) ? a : gcd(b, a%b);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> f[i];
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        int x = f[i];
        long long loop = 1;
        while (x != i) {
            x = f[x];
            loop++;
        }
        ans = ans * loop / gcd(ans, loop);
    }
    cout << ans << endl;
    return 0;
}
