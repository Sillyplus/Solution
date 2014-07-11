#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MN = 1010;

int n, m, k, w;
char v[MN][11][11];
int f[MN] = {0};
vector<int> vt[MN];

struct edge{
    int x, y, byt;
    bool operator < (edge ot) const {
        return byt < ot.byt;
    }
} e[MN * MN];

inline int cal(int x, int y) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[x][i][j] != v[y][i][j])
                ret++;
        }
    }
    return ret;
}

int getf(int x) {
    return f[x] == x ? x : f[x] = getf(f[x]);
}

void pt(int cur, int from) {
    if (cur != 0)
        cout << cur << ' ' << from << endl;
    for (int i = 0; i < vt[cur].size(); i++) {
        if (vt[cur][i] != from)
            pt(vt[cur][i], cur);
    }
}

int main() {
    cin >> n >> m >> k >> w;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    int ne = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = i+1; j <= k; j++) {
            ne++;
            e[ne].x = i;
            e[ne].y = j;
            if (i == 0)
                e[ne].byt = n*m;
            else
                e[ne].byt = w * cal(i-1, j-1);
        }
    }

    sort(e+1, e+1+ne);
    for (int i = 0; i <= k; i++)
        f[i] = i;
    long long ans = 0;
    for (int i = 1; i <= ne; i++) {
        int fa = getf(e[i].x);
        int fb = getf(e[i].y);
        if (fa != fb) {
            f[fa] = fb;
            vt[e[i].x].push_back(e[i].y);
            vt[e[i].y].push_back(e[i].x);
            ans += e[i].byt;
        }
    }

    cout << ans << endl;
    pt(0, -1);
    return 0;
}
