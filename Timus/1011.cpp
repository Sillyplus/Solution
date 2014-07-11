#include <iostream>

using namespace std;

int main() {
    double p, q;
    int ans = 1, x = 0, y = 0;
    cin >> p >> q;
    p += 1e-10;
    q -= 1e-10;
    while (x == y) {
        ans++;
        x = int (ans * p) / 100;
        y = int (ans * q) / 100;
        //cout << x << ' ' << y << endl;;
    }
    cout << ans << endl;
    return 0;
}
