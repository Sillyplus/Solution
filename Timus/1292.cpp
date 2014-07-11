#include <iostream>
#include <cstdio>

using namespace std;

long long a[10] = {0, 1, 8, 27, 64, 125, 216, 343, 512, 729};

long long msk(long long x) {
    int k;
    long long tmp = 0;
    while (x) {
        k = x % 10;
        tmp += a[k];
        x /= 10;
    }
    return tmp;
}

int main() {
    long long n, k, l;
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k >> l;
        for (int i = 1; i < n; i++) {
            k = msk(k);
            if (k == 153) break;
        }
        cout << k - l << endl;
    }
    return 0;
}
