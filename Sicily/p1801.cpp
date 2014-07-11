#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MN = 110;

struct aa{
    int t, nb;
};

vector<int> v[MN];
aa a[MN];
bool f[MN];
int b[MN];
int ans = 0;

bool cmp(const aa &a, const aa &b) {
    if (a.t != b.t) return a.t < b.t;
    return a.nb < b.nb;
}

void ss(int k) {
    for (int j = 0; j < v[k].size(); j++) {
        if (!f[v[k][j]]) {
            ans += (b[v[k][j]] / 2);
            f[v[k][j]] = true;
            ss(v[k][j]);
        }
    }
}
int main() {
    int n, m, x, y;
    cin >> n >> m;
    while (!(n==0 && m==0)) {
        memset(f, false, sizeof(f));
        for (int i = 0; i < n; i++) v[i].clear();
        for (int i = 0; i < n; i++) {
            a[i].nb = i;
            cin >> a[i].t;
            b[i] = a[i].t;
        }
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        sort(a, a+n, cmp);
        ans = 0;
        for (int i = 0; i < n; i++) {
            int k = a[i].nb;
            if (!f[k]) {
                ans += b[k];
                f[k] = true;
                ss(k);
            }
        }
        cout << ans << endl;
        cin >> n >> m;
    }
    return 0;
}
