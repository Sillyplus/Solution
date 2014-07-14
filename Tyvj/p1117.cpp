#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

struct pt{
    int row, cul;
};

bool vis[30][30];
int dis[30][30], a[30][30];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int t, x, y;
pt st, ed;
queue<pt> q;

bool check(pt p) {
    if (p.row >= 0 && p.cul >= 0 && p.row < y && p.cul < x)
        return true;
    return false;
}

int main() {
    cin >> t >> x >> y;
    getchar();
    char c;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            cin >> c;
            if (c == '.') {
                a[i][j] = 1;
            }
            if (c == '#') {
                a[i][j] = 2;
            }
            if (c == 'o') {
                a[i][j] = 1000000000;
            }
            if (c == 's') {
                st.row = i;
                st.cul = j;
            }
            if (c == 'm') {
                ed.row = i;
                ed.cul = j;
                a[i][j] = 1;
            }
        }
        getchar();
    }
    pt now, next;
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < 30; i++)
        for (int j = 0; j < 30; j++)
            dis[i][j] = 1000000000;
    q.push(st);
    vis[st.row][st.cul] = true;
    dis[st.row][st.cul] = 0;
    while (!q.empty()) {
        now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            next.row = now.row + dx[i];
            next.cul = now.cul + dy[i];
            if (check(next)) {
                if (dis[now.row][now.cul] + a[next.row][next.cul] < dis[next.row][next.cul]) {
                    dis[next.row][next.cul] = dis[now.row][now.cul] + a[next.row][next.cul];
                    if (!vis[next.row][next.cul]) {
                        q.push(next);
                        vis[next.row][next.cul] = true;
                    }
                }
            }
        }
    }
    if (dis[ed.row][ed.cul] < t)
        cout << dis[ed.row][ed.cul] << endl;
    else
        cout << 55555 << endl;
    return 0;
}
