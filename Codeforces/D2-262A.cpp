#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MN = 10010;

int n, m;

int main() {
    int ans;
    cin >> n >> m;
    ans = n;
    while (n/m) {
        ans += n/m;
        n = n/m + n%m;
    }
    cout << ans << endl;
    return 0;
}
