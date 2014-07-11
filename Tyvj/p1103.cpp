#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

int n, k, t;
int a[10010];

int main() {
    cin >> n;
    t = 0;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0) t++;
    }
    if (t == n+1) {
        cout << 0 << endl;
        return 0;
    }
    if (n > 1) {
        if (a[0] != 0) {
            if (a[0] == 1) {
                cout << "x^" << n;
            } else if (a[0] == -1) {
                cout << "-x^" << n;
            } else {
                cout << a[0] << "x^" << n;
            }
        }
    }
    for (int i = 1; i < n-1; i++) {
        if (a[i] != 0) {
            if (a[i] == 1) {
                cout << "+x^" << (n-i);
            } else if (a[i] == -1) {
                cout << "-x^" << (n-i);
            } else {
                if (a[i] > 0) {
                    cout << '+';
                }
                cout << a[i] << "x^" << (n-i);
            }
        }
    }
    if (n > 0) {
        if (a[n-1] != 0) {
            if (a[n-1] == 1) {
                cout << "+x";
            } else if (a[n-1] == -1) {
                cout << "-x";
            } else {
                if (a[n-1] > 0) {
                    cout << '+';
                }
                cout << a[n-1] << 'x';
            }
        }
    }
    if (a[n] != 0) {
        if (a[n] > 0) {
            cout << '+';
        }
        cout << a[n] << endl;
    }
    return 0;
}
