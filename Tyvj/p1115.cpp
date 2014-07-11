#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int a[110];
int b[100010];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    int ans = a[1]-a[0];
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            ans = gcd(ans, a[j]-a[i]);
    cout << ans << endl;
    return 0;
}
