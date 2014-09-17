#include <iostream>

using namespace std;

int main() {
    int a1, a2, a3, b1, b2, b3;
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    cin >> a3 >> b3;
    int ans1 = a1 - a3;
    int ans2 = b1 - b2;
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}


