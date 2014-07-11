#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = min(n, 1); i <= max(n, 1); i++)
        ans += i;
    cout << ans << endl;
    return 0;
}
