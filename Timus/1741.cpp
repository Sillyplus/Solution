/*******************************************************************************
    > File Name: 1741.cpp
    > Author: sillyplus
    > Mail: oi_boy@sina.cn
    > Created Time: Mon Dec 14 17:08:18 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;
typedef long long LL;

struct pk {
    int v1, v2;
    LL sz;
    string lc;
};

pk a[MAXN];
LL f[MAXN][2];
map<string, int> mp;

bool cmp(const pk& x, const pk& y) {
    if (x.v1 == y.v1) {
        return x.v2 < y.v2;
    }
    return x.v1 < y.v1;
}

int main(int argc, char* argv[]) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i].v1 >> a[i].v2 >> a[i].sz >> a[i].lc;
    }
    memset(f, 0x3f, sizeof(f));
    LL INF = f[0][0];
    sort(a, a + m, cmp);
    f[1][0] = 0;
    mp["Licensed"] = 0;
    mp["Cracked"] = 1;
    mp["Pirated"] = 2;
    for (int i = 0; i < m; ++i) {
        int v1 = a[i].v1, v2 = a[i].v2, sz = a[i].sz, lc = mp[a[i].lc];
        if (lc == 0) {
            f[v2][0] = min(f[v2][0], f[v1][0] + sz);
        } else if (lc == 1) {
            f[v2][0] = min(f[v2][0], f[v1][0] + sz);
            f[v2][1] = min(f[v2][1], f[v1][1] + sz);
        } else {
            f[v2][1] = min(f[v2][1], min(f[v1][0], f[v1][1]) + sz);
        }
    }
    LL ans = min(f[n][0], f[n][1]);
    if (ans != INF) {
        cout << "Online" << endl;
        cout << ans << endl;
    } else {
        cout << "Offline" << endl;
    }
    return 0;
}
