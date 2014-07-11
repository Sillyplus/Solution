#include <iostream>

typedef long long LL;

using namespace std;

const int MN = 70;

LL cb[MN][MN] = {0};

void init() {
    for (int i = 0; i <= 62; i++) {
        cb[i][0] = cb[i][i] = 1;
        for (int j = 1; j < i; j++)
            cb[i][j] = cb[i-1][j-1] + cb[i-1][j];
    }
}

LL cal(LL x, LL k) {
    LL ret = 0, dig = 0;
    for (int i = 62; i >= 0; i--) {
        if (((1LL << i) & x) != 0) {
            ret += cb[i][k-dig];
            dig++;
            if (dig > k) break;
        }
    }
    return ret;
}

int main() {
    init();
    LL m, k;
    cin >> m >> k;
    LL left = 0, right = 1e18, mid;
    while ((right - left) > 1) {
        mid = (left+right) / 2;
        if ((cal(mid*2, k) - cal(mid, k)) >= m)
            right = mid;
        else
            left = mid;
    }
    cout << right << endl;
    return 0;
}
