#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int a[310];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    int ans = 0;
    for (int i = 0; i < (n/2); i++)
        ans += abs(a[i] - a[n-i-1]);
    cout << ans*2 << endl;
    return 0;
}
