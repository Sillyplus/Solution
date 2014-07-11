#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int MN = 50010;

int st[MN][32][2];
int a[MN], pl[MN];
int n, m;

void stp(int n) {
    pl[1] = 0;
    for (int i = 2; i <= n; i++) {
        pl[i] = pl[i-1];
        if ((1 << (pl[i]+1)) == i) {
            pl[i]++;
        }
    }
    for (int i = n-1; i >= 0; i--) {
        st[i][0][0] = st[i][0][1] = a[i];
        for (int j = 1; (i + (1 << j) - 1) < n; j++) {
            st[i][j][0] = max(st[i][j-1][0], st[i + (1 << (j-1))][j-1][0]);
            st[i][j][1] = min(st[i][j-1][1], st[i + (1 << (j-1))][j-1][1]);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    stp(n);
    int l, r, len, k, mx, mi;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &l, &r);
        l--;
        r--;
        len = r-l+1;
        k = pl[len];
        mx = max(st[l][k][0], st[r-(1<<k)+1][k][0]);
        mi = min(st[l][k][1], st[r-(1<<k)+1][k][1]);
        printf("%d %d\n", mx, mi);
    }
    return 0;
}
