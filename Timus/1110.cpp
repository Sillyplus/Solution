#include <iostream>

using namespace std;

int n, m, y;

int km(int a, int b) {
    if (b == 0) return 1 % m;
    int temp = km(a, b>>1);
    temp = temp*temp % m;
    if (b & 1) temp = temp*a % m;
    return temp;
}

int main() {
    cin >> n >> m >> y;
    bool flag = false;
    for (int i = 0; i < m; i++)
        if (km(i, n) == y) {
            cout << i << ' ';
            flag = true;
        }
    if (!flag) cout << -1;
    cout << endl;
    return 0;
}
