#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MN = 510;

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
int mp[MN][MN];
int n, m;
char c;

bool check(int x, int y) {
    if(x >= 1 && y >= 1 && x <= n && y <= m)
        return true;
    return false;
}

void dfs1(int x, int y) {
    if (mp[x][y] == 1) {
        mp[x][y] = 2;
        for (int i = 0; i < 8; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (check(xx, yy))
                dfs1(xx, yy);
        }
    }
}

void dfs2(int x, int y) {
    if (mp[x][y] != 2 && mp[x][y] != 3) {
        mp[x][y] = 3;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (check(xx, yy))
                dfs2(xx, yy);
        }
    }
}

void dfs3(int x, int y) {
    if (mp[x][y] == 0) {
        mp[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (check(xx, yy))
                dfs3(xx, yy);
        }
    }
}

int main() {
    int x, y;
    cin >> m >> n >> y >> x;
    getchar();
    memset(mp, 0, sizeof(mp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%c", &c);
            if (c == '.') {
                mp[i][j] = 1;
            }
        }
        getchar();
    }
    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cout << mp[i][j];
        cout << endl;
    }
    */
    dfs1(x, y);
    for (int i = 1; i <= m; i++) {
        if (mp[1][i] != 2)
            dfs2(1, i);
        if (mp[n][i] != 2)
            dfs2(n, i);
    }
    for (int i = 1; i <= n; i++) {
        if (mp[i][1] != 2)
            dfs2(i, 1);
        if (mp[i][m] != 2)
            dfs2(i, m);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!mp[i][j]) {
                dfs3(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
