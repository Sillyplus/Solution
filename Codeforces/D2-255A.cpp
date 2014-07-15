#include <iostream>
#include <cstring>

using namespace std;

const int MN = 500;

int p, n, x;
bool f[MN] = {0};

int main() {
    cin >> p >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (f[x % p]) {
            cout << i+1 << endl;
            return 0;
        } else {
            f[x % p] = true;
        }
    }
    cout << -1 << endl;
    return 0;
}
