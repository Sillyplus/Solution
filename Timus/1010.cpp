#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const int MN = 100010;

double a[MN];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%lf", &a[i]);
    int ans;
    double temp, now = -1.0;
    for (int i = 1; i < n; i++) {
        temp = fabs(a[i] - a[i+1]);
        if (temp > now) {
            now = temp;
            ans = i;
        }
    }
    cout << ans << ' ' << ans+1 << endl;
    return 0;
}
