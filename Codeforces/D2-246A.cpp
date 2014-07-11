#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int MN = 10010;

int main() {
    int n, m, x, ans = 0;
    cin >> n >> m;
    m = 5-m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x <= m) ans++;
    }
    cout << ans/3 << endl;
    return 0;
}
