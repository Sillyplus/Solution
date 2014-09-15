#include <iostream>
#include <utility>
#include <cstdio>
#include <cstring>

using namespace std;

const int MN = 520;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int dis[MN][MN] = {0};
bool vt[MN][MN];
char map[MN][MN];
pair<int, int> q[MN*MN];

int n, m, x1, x2, y1, y2;
int ans, nop;

void dfs(int x, int y, char ch, int depth) {
    vt[x][y] = true;
    q[++nop] = make_pair(x, y);
    dis[x][y] = depth;
    if (x == x2 && y == y2) {
        ans = depth;
        return;
    }
    int xx, yy;
    for (int i = 0; i < 4; i++) {
        xx = x + dx[i];
        yy = y + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m &&
            !vt[xx][yy] && map[xx][yy] == ch) {
                dfs(xx, yy, ch, depth);
            }
    }
}

void bfs() {
    memset(vt, false, sizeof(vt));
    ans = -1;
    nop = -1;
    dfs(x1, y1, map[x1][y1], 0);
    if (ans >= 0) {
        printf("%d\n", ans);
        return;
    }
    int x, y, xx, yy, depth;
    for (int i = 0; i <= nop; i++) {
        x = q[i].first;
        y = q[i].second;
        depth = dis[x][y];
        for (int j = 0; j < 4; j++) {
            xx = x + dx[j];
            yy = y + dy[j];
            if (xx >= 0 && xx < n && yy >= 0 && y < m && !vt[xx][yy]) {
                dfs(xx, yy, map[xx][yy], depth+1);
                if (ans >= 0) {
                    printf("%d\n", ans);
                    return;
                }
            }
        }
    }
}

int main() {
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 0; i < n; i++)
            scanf("%s", map[i]);
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        bfs();
    }
    return 0;
}
