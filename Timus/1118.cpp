#include <iostream>
#include <cstring>

using namespace std;

const int MN = 1000010;

double f[MN];

int main() {
    int l, r;
    cin >> l >> r;
    memset(f, 1, sizeof(f));
    f[1] = 0;
    for (int i = 2; i <= r/2; i++) {
        for (int j = i+i; j<= r; j += i) f[j] += i;
    }
    double ratio = 1000000.1;
    int ans;
    for (int i = l; i <= r; i++) {
        double k = f[i] / (i*1.0);
        if (k < ratio) {
            ans = i;
            ratio = k;
        }
    }
    cout << ans << endl;
    return 0;
}
