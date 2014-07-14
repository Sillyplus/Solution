#include <iostream>

using namespace std;

int main() {
    int n;
    long long ans = 8, tp = 1;
    cin >> n;
    for (int i = 1; i < n; i++) {
        ans = ans * 8 + 9 * tp;
		tp *= 10;
    }
    cout << ans << endl;
    return 0;
}
