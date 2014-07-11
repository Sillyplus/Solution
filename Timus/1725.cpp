#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n == 2) {
        cout << 0 << endl;
        return 0;
    }
    if (m > (n/2))
        m = n - m + 1;
    cout << (n-m-2) << endl;
    return 0;
}
