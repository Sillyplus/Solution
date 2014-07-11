#include <iostream>

using namespace std;

long long n, a, b;

int main() {
    cin >> n >> a >> b;
    long long k, x;
    for (int i = 1; i < n ; i++) {
        cin >> k;
        x = k*a/b;
        if (a == 0) {cout << k << ' '; continue;}
        if ((k*a%b) == 0) {
            cout << 0 << ' ';
        } else {
            cout << (k*a - b*x)/a << " ";
        }
    }
    cin >> k;
    x = k*a/b;
    if ((k*a%b) == 0) {
        cout << 0 << endl;
    } else {
        if (x == 0) {cout << k << endl; return 0;}
        cout << (k*a - b*x)/a << endl;
    }
    return 0;
}
