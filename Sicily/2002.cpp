/*******************************************************************************
	> File Name: 2002.cpp
	> Author: sillyplus
	> Mail: oi_boy@sina.cn
	> Created Time: Wed Nov 26 16:14:34 2014
 ******************************************************************************/

#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 760;

bool v[MAXN][MAXN];
char c[MAXN][MAXN];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
queue<pair<int, int> > q;

int w, h, ans;

bool check(int x, int y) {
    if (x < 0 || x >= h || y < 0 || y >= w)
        return false;
    else
        return (v[x][y] && (c[x][y] == '.'));
}

int search(int x, int y) {
    int ret = 1;
    q.push(make_pair(x, y));
    v[x][y] = false;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int tx = p.first + dx[i];
            int ty = p.second + dy[i];
            if (check(tx, ty)) {
                ret++;
                q.push(make_pair(tx, ty));
                v[tx][ty] = false;
            } else {
                continue;
            }
        }
    }
    return ret;
}

int main() {
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
        cin >> c[i];
    }
    memset(v, true, sizeof(v));
    while (!q.empty()) q.pop();
    ans = -1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (c[i][j] == '.' && v[i][j]) {
                int tmp = search(i, j);
                ans = max(ans, tmp);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
