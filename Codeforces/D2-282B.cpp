#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << "infinity" << endl;
    } else {
        int ans = 0;
        a -= b;
        for (int i = 1; i <= sqrt(a); i++) {
            if (a % i == 0) {
                if (i * i == a)
                    ans += (i > b);
                else
                    ans += (i > b) + (a/i > b);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
