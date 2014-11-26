#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, m;
    while (scanf("%d%d", &m, &n) && (n != 0 && m != 0)) {
        int x, y;
        y = n - 2 * m;
        if (y % 2 == 0) {
            y /= 2;
            x = m - y;
            if (x >= 0 && y >= 0) {
                cout << x << ' ' << y << endl;
            } else {
                cout << "No answer" << endl;
            }
        } else {
            cout << "No answer" << endl;
        }
    }
    return 0;
}
