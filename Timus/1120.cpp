#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, a, p;
    cin >> n;
    for (int p = sqrt(2*n); p >= 1; p--) {
        if (2*n % p == 0) {
            int k = 2*n / p - p + 1;
            if (k > 0 && k % 2 == 0) {
                cout << k/2 << ' ' << p << endl;
                return 0;
            }
        }
    }
    return 0;
}
