#include <iostream>
#include <cmath>

using namespace std;

int k, n, x;

int main() {
    cin >> k >> n;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cur = max(0, cur+x - k);
    }
    cout << cur << endl;
    return 0;
}
