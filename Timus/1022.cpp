#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MN = 110;

struct arr{
    int x, y;
};

int f[MN][MN] = {0};
arr a[MN];

bool cmp(const arr &x, const arr &y) {
    if (x.x != y.x)
        return x.x > y.x;
    else
        return x.y < y.y;
}

int main() {
    int n, k;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        while (k) {
            f[i][k] = 1;
            cin >> k;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            a[i].y = i;
            for (int j = 1; j <= n; j++) {
                if (f[i][k] && f[k][j])
                    f[i][j] = f[i][k] + f[k][j];
                a[i].x = max(a[i].x, f[i][j]);
            }
        }
    }
    sort(a+1, a+n+1, cmp);
    for (int i = 1; i <= n; i++)
        cout << a[i].y << ' ';
    cout << endl;
    return 0;
}
