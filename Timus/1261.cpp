#include <iostream>

using namespace std;

int a[100];

int main() {
    int n, m = 1, x = 0, y = 0;
    cin >> n;
    x = n;
    do {
        if (n % 3 == 2) {
            y += m;
            n++;
        }
        n /= 3;
        m *= 3;
    } while (n);
    if (!y) y = m;
    cout << x + y << ' ' << y << endl;
    return 0;
}
