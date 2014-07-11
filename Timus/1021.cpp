#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 70000;

int a[MN] = {0}, b[MN] = {0};

int main() {
    int n, m, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        a[k+32768] = 1;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        b[k+32768] = 1;
    }
    for (int i = 0; i < 32768; i++) {
        if ((a[i+32768] && b[10000-i+32768]) || (b[i+32768] && a[10000-i+32768])){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
