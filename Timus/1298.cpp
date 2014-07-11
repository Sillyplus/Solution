#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MN = 10;

bool flag = false;
int map[MN][MN] = {0}, ax[MN*MN] = {0}, ay[MN*MN] = {0};
int dx[MN] = {-2,-1, 1, 2, 2, 1,-1,-2};
int dy[MN] = { 1, 2, 2, 1,-1,-2,-2,-1};
int n, step = 0;

void dfs(int x, int y) {
    if (flag) return;
    ax[step] = x;
    ay[step] = y;
    step++;
    if (step == n*n) {
        flag = true;
        return;
    }
    map[x][y] = 1;
    for (int k = 0; k < 8; k++) {
        int xx, yy;
        xx = x + dx[k];
        yy = y + dy[k];
        if (map[xx][yy] == 0 && xx > 0 && xx <= n && yy > 0 && yy <= n) {
            dfs(xx, yy);
            step--;
        }
    }
    map[x][y] = 0;
}

int main() {
    cin >> n;
    memset(map, 0, sizeof(map));
    dfs(1, 1);
    if (flag) {
        for (int i = 0; i < n*n; i++) {
            cout << char('a'+ay[i]-1) << ax[i] << endl;
        }
    } else cout << "IMPOSSIBLE" << endl;
    return 0;
}
