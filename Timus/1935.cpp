#include <iostream>

using namespace std;

int main() {
    int n, k, x = 0;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        ans += k;
        if (k > x)
            x = k;
    }
    cout << ans+x << endl;;
    return 0;
}
