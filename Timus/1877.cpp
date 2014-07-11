#include <iostream>

using namespace std;

char c[10];

int main() {
    int ans = 0;
    cin >> c;
    if ((c[3] - '0') % 2 == 0) ans = 1;
    cin >> c;
    if ((c[3] - '0') % 2) ans = 1;
    if (ans) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}
