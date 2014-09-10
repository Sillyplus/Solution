#include <iostream>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MN = (1 << 15) + 10;

int sum[MN] = {0};
int f[MN] = {0};

int main() {
    int n, l, r, mi, mx, ans, k;
    cin >> n;
    while (n) {
        scanf("%d%d", &mi, &mx);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &k);
            sum[i] = sum[i-1] + k;
        }
        l = r = 0;
        f[++r] = 0;
        ans = 2147483647;
        for (int i = mi; i <= n; i++) {
            while (l < r && i - f[l+1] > mx) l++;
            while (l < r && sum[f[r]] <= sum[i-mi]) r--;
            f[++r] = i - mi;
            ans = min(ans, sum[i] - sum[f[l+1]]);
        }
        printf("%d\n", ans);
        cin >> n;
    }
    return 0;
}
