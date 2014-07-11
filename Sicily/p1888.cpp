#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MN = 100000;

int a[MN];
int n = 0, t;

LL max_sum() {
    LL ret = a[0];
    LL tmp = a[0];
    for (int i = 1; i < n; i++) {
        if (tmp < 0) {
            tmp = a[i];
        } else {
            tmp += a[i];
        }
        ret = max(ret, tmp);
    }
    return ret;
}

LL min_sum() {
    if (n <= 2) {
        return 0;
    }
    LL ret = a[1];
    LL tmp = a[1];
    for (int i = 2; i < n-1; i++) {
        if (tmp > 0) {
            tmp = a[i];
        } else {
            tmp += a[i];
        }
        ret = min(ret, tmp);
    }
    return ret;
}

int main(){
    cin >> t;
    while (t--) {
        cin >> n;
        LL sum = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            sum += a[i];
        }
        LL ans = max(max_sum(), sum - min_sum());
        printf("%lld\n", ans);
    }
    return 0;
}
