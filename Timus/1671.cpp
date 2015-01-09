/*******************************************************************************
	> File Name: 1671.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri Jan  9 08:57:09 2015
 ******************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 1e5 + 10;

int f[MAXN];
int ans[MAXN];
int Q[MAXN];
bool flag[MAXN];
vector<pair<int, int> > v(MAXN);

int father(int x) {
    if (f[x] == x) 
        return x;
    else 
        return f[x] = father(f[x]);
}

int main() {
    int n, m, q;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &v[i].first, &v[i].second);
    }
    cin >> q;
    memset(flag, true, sizeof(flag));
    for (int i = 0; i < q; i++) {
        scanf("%d", &Q[i]);
        flag[Q[i]] = false;
    }
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= m; i++) {
        if (flag[i]) {
            int fa = father(v[i].first);
            int fb = father(v[i].second);
            if (fa != fb)
                f[fa] = fb;
        }
    }
    int tmp = 0;
    for (int i = 1; i <= n; i++)
        if (f[i] == i) tmp++;
    ans[q] = tmp;
    for (int i = q-1; i >= 1; i--) {
        if (father(v[Q[i]].first) != father(v[Q[i]].second)) {
            tmp--;
            f[f[v[Q[i]].first]] = f[f[v[Q[i]].second]];
        } 
        ans[i] = tmp;
    }
    for (int i = 1; i <= q; i++)
        printf("%d ", ans[i]);
    cout << endl;
    return 0;
}
