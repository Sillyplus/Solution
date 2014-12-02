#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 1e6 + 10;

typedef long long LL;

struct exam{
    int a, b;
};

exam v[MAXN];

bool cmp(const exam &x, const exam &y) {
    if (x.b != y.b)
        return (x.b < y.b);
    else
        return (x.a < y.a);
}

int main() {
    LL n, r, avg, tmp = 0;
    cin >> n >> r >> avg;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &v[i].a, &v[i].b);
        tmp += v[i].a;
    }
    sort(v, v+n, cmp);
    LL sum = n*avg, ans = 0;
    for (int i = 0; i < n; i++) {
        if (tmp >= sum) {
            break;
        }
        if (v[i].a < r) {
            if (tmp + (r - v[i].a) > sum) {
                ans += (sum - tmp) * v[i].b;
                tmp = sum;
            } else {
                ans += (r - v[i].a) * v[i].b;
                tmp += r - v[i].a;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
