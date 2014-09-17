#include <iostream>

using namespace std;

int gcd(int x, int y) {
    return (y == 0 ? x : gcd(y, x%y));
}

int main() {
    int t, a, b, c, d;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        int cm = (b * d) / gcd(b, d);
        int sum = (cm / b * a) + (cm / d * c);
        int cd = gcd(cm, sum);
        cm /= cd;
        sum /= cd;
        if (cm == 1) {
            cout << sum << endl;
        } else {
            cout << sum << "/" << cm << endl;
        }
    }
    return 0;
}
