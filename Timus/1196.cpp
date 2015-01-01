#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<int, int> a;

int main() {
    int n, m, k, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        a[k]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        ans += a[k];
    }
    cout << ans << endl;
    return 0;
}

