#include <iostream>
#include <cmath>

using namespace std;

const int MN = 10010;

int n, k;
int f[MN] = {0};

int main() {
    cin >> n >> k;
    if (k > n) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            f[(i+j)%k]++;
        }
    }
    int ans = MN*MN;
    for (int i = 0; i < k; i++)
        ans = min(ans, f[i]);
    cout << ans << endl;
    return 0;
}
