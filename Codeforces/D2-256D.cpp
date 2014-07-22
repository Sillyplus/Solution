#include <iostream>
#include <cmath>

typedef long long LL;

using namespace std;

LL n, m, k;

LL get(LL ans) {
    LL ret = 0;
    for (int i = 1; i <= n; i++) {
        ret += min(LL(m), ans/LL(i));
    }
    return ret;
}

int main() {
    cin >> n >> m >> k;
    LL l, r;
    l = 1;
    r = n*m;
    while (l < r) {
        LL mid = (l+r) >> 1;
        if (get(mid) >= k)
            r = mid;
        else
            l = mid+1;
    }
    cout << r << endl;
    return 0;
}
