#include <iostream>

using namespace std;

int n, k;

void pta(int x) {
    if (x == k) {
        cout << "sin(" << x << ")";
        return;
    }
    cout << "sin(" << x;
    cout << ((x%2) ? '-':'+');
    pta(x+1);
    cout << ')';
}

void pts(int x) {
    if (x == n) {
        k = 1;
        pta(1);
        cout << '+' << x;
        return;
    }
    cout << '(';
    pts(x+1);
    cout << ')';
    k = n-x+1;
    pta(1);
    cout << '+' << x;
}

int main() {
    cin >> n;
    pts(1);
    cout << endl;
    return 0;
}
