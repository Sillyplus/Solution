#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int MN = 32000;

int f[MN];
int n, ans, x;

int main() {
    cin >> n;
    int l, r, mid;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        l = 1;
        r = f[0];
        while (l < r) {
            mid = (l+r) >> 1;
            if (f[mid] <= x)
                l = mid+1;
            else
                r = mid;
        }
        if ((l >= r) && (x >= f[f[0]])) {
            f[0]++;
            f[f[0]] = x;
            l = f[0];
        } else {
            if (x < f[l])
                f[l] = x;
        }
    }
    cout << f[0] << endl;
    return 0;
}
