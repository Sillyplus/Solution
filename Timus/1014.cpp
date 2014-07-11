#include <iostream>

using namespace std;

int f[10];

int sol(int k) {
    int x = 9;
    while ((k != 1) && (x > 1)) {
        while (k % x == 0) {
            f[x]++;
            k /= x;
        }
        x--;
    }
    return k;
}

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 10 << endl;
        return 0;
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    int ans = sol(n);
    if (ans == 1) {
        for (int i = 1; i <= 9; i++)
            if (f[i]) for (int j = 0; j < f[i]; j++) cout << i;
    } else cout << -1;
    cout << endl;
    return 0;
}
