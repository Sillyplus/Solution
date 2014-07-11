#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long x, y;
    cin >> x >> y;
    if (((x+y) % 2) != 0 && (x > 0 && y > 0)) cout << y << ' ' << x<< endl;
        else cout << x << ' ' << y << endl;
    return 0;
}
