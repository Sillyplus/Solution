#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int MN  = 180;

struct pos{
    int x, y;
    int level;
};

int n, m;
pos k, h;
char c[MN][MN];
int ans = 0;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
bool vis[MN][MN];
queue<pos> q;

bool check(int x, int y) {
    if (x >= 0 && y >= 0 && x < n && y < m) {
        if (c[x][y] == 'H' || c[x][y] == '.')
            return true;
    }
    return false;
}

void bfs(pos p) {
    pos now, next;
    p.level = 0;
    q.push(p);
    vis[p.x][p.y] = true;
    while (!q.empty()) {
        now = q.front();
        if ((now.x == h.x) && (now.y == h.y)) {
            ans = now.level;
            return;
        }
        for (int i = 0; i < 8; i++) {
            int tx, ty;
            tx = now.x + dx[i];
            ty = now.y + dy[i];
            if (check(tx, ty) && !vis[tx][ty]) {
                next.x = tx;
                next.y = ty;
                next.level = now.level+1;
                q.push(next);
                vis[tx][ty] = true;
            }
        }
        q.pop();
    }
}

int main() {
    cin >> m >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%c", &c[i][j]);
            if (c[i][j] == 'K') {
                k.x = i;
                k.y = j;
            } else if (c[i][j] == 'H') {
                h.x = i;
                h.y = j;
            }
        }
        getchar();
    }
    memset(vis, false, sizeof(vis));
    bfs(k);
    cout << ans << endl;
    return 0;
}
