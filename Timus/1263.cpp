#include <iostream>
#include <cstdio>

using namespace std;

int a[10010] = {0};

int main() {
    int n, m, k;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> k;
        a[k]++;
    }
    double ans;
    for (int i = 1; i <= n; i++) {
            ans = a[i] / (m*1.0) * 100;
            printf("%.2f", ans);
            cout << "%\n";
    }
    return 0;
}
