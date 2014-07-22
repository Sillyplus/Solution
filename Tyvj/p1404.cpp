#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int MN = 510;

int n, m, root;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int a[MN][MN];
int l[MN], r[MN], f[MN];
bool vis[MN][MN];
bool last[MN];

bool ck(int x, int y) {
    return (x > 0 && y > 0 && x <= n && y <= m);
}

void sc(int x, int y) {
    vis[x][y] = true;
    if (x == n) {
        last[y] = true;
        l[root] = min(l[root], y);
        r[root] = max(r[root], y);
    }
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (ck(tx, ty)) {
            if ((a[x][y] > a[tx][ty]) && (!vis[tx][ty]))
                sc(tx, ty);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    memset(last, false, sizeof(last));
    for (int i = 0; i < MN; i++)
        l[i] = MN;
    for (int i = 1; i <= m; i++)
        if ((a[1][i] >= a[1][i-1]) && (a[1][i] >= a[1][i+1])) {
            memset(vis, false, sizeof(vis));
            root = i;
            sc(1, i);
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
        if (!last[i]) ans++;
    if (ans) {
        cout << 0 << endl << ans << endl;
        return 0;
    }
    f[0] = 0;
    for (int i = 1; i <= m; i++)
        f[i] = MN;
    for (int i = 1; i <= m; i++)
        for (int j = l[i]; j <= r[i]; j++)
            f[j] = min(f[j], f[l[i]-1] + 1);
    cout << 1 << endl;
    cout << f[m] << endl;
    return 0;
}
