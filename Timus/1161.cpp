#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

double a[110];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    //cout << a[0] << endl;
    for (int i = n-2; i >= 0; i--) {
        a[i] = 2 * sqrt(a[i]*a[i+1]);
    }
    printf("%.2f\n", a[0]);
    return 0;
}
