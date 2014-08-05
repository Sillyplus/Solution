#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int MN = 1010;

struct pos{
    int x, y, deep;
};

queue<pos> q;

bool vis[MN][MN];
int a[MN][MN], b[MN][MN];
char c[MN][MN];
int n, m;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

bool check(pos t) {
    bool ret = (t.x >= 0 && t.y >= 0 && t.x < n && t.y < m);
    if (ret) {
        if (vis[t.x][t.y] || (c[t.x][t.y] == '*')) ret = false;
    }
    return ret;
}

void bfs(pos sr, int d[][MN]) {
    memset(vis, false, sizeof(vis));
    while (!q.empty()) q.pop();
    q.push(sr);
    vis[sr.x][sr.y] = true;
    d[sr.x][sr.y] = sr.deep;
    while (!q.empty()) {
        pos now, next;
        now = q.front();
        for (int i = 0; i < 4; i++) {
            next.x = now.x + dx[i];
            next.y = now.y + dy[i];
            if (check(next)) {
                next.deep = now.deep+1;
                d[next.x][next.y] = next.deep;
                q.push(next);
                vis[next.x][next.y] = true;
            }
        }
        q.pop();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    memset(a, 63, sizeof(a));
    memset(b, 63, sizeof(b));
    int INF = a[0][0]; //!!!!!!
    pos sro, orz, l, r;
    sro.x = sro.y = sro.deep = 0;
    orz.x = n-1, orz.y = m-1, orz.deep = 0;
    bfs(sro, a);
    bfs(orz, b);
    int ans = INF;
    ans = min(ans, a[n-1][m-1]);
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (c[i][j] == '*') {
            for (int p = 0; p < 4; p++) {
                l.x = i+dx[p], l.y = j+dy[p];
                if (check(l))
                    for (int q = 0; q < 4; q++) if (p != q) {
                        r.x = i+dx[q], r.y = j+dy[q];
                        if (check(r)) {
                            ans = min(ans, a[l.x][l.y]+b[r.x][r.y]+2);
                        }
                    }
            }
        }
    }
    if (ans != INF)
        cout << ans << endl;
    else
        cout << "no" << endl;
    return 0;
}
