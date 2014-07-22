#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MM = 5050;
const int INF = 1000000000;

struct edge{
    int x, y, w;
    bool operator < (const edge & a) const {
        return w < a.w;
    }
} e[MM];

int n, m, t, v, k, p;
bool can[MM], road[MM][MM];
int f[MM/10], fa[MM];

int getfa(int x) {
    return (fa[x] == x ? x : fa[x] = getfa(fa[x]));
}

int kruskal(int t1, int t2) {
    memset(can, true, sizeof(can));
    for (int i = 1; i <= m; i++)
        for (int j = t1; j <= t2; j++)
            if (!road[i][j]) {
                can[i] = false;
                break;
            }
    for (int i = 1; i <= m; i++)
        fa[i] = i;
    int ret = 0, cnt = 0;
    for (int i = 1; i <= m; i++)
        if (can[i]) {
            int f1 = getfa(e[i].x);
            int f2 = getfa(e[i].y);
            if (f1 != f2) {
                fa[f1] = f2;
                ret += e[i].w;
                cnt++;
                if (cnt == n-1)
                    return ret;
            }
        }
    return INF;
}

int main() {
    cin >> n >> m >> t >> v >> k;
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w);
    sort(e+1, e+1+m);
    cin >> p;
    memset(road, true, sizeof(road));
    for (int i = 0; i < p; i++) {
        int x, y, t1, t2;
        scanf("%d%d%d%d", &x, &y,&t1, &t2);
        for (int j = 1; j <= m; j++)
            if (((e[j].x == x) && (e[j].y == y)) || ((e[j].x == y) && (e[j].y == x))) {
                for (int tt = t1; tt <= t2; tt++)
                    road[j][tt] = false;
            }
    }
    for (int i = 1; i <= t; i++)
        f[i] = INF;
    for (int i = 1; i <= t; i++)
        for (int j = 1; j <= i; j++)
            f[i] = min(f[i], f[j-1]+kruskal(j, i)*(i-j+1)*v+k);
    cout << f[t] << endl;
    return 0;
}
