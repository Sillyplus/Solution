#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MN = 20;

char c[MN][MN], ans[MN][MN];
int n, m;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

bool check(int x, int y) {
    int tmp = 0;
    int tx, ty;
    for (int i = 0; i < 4; i++) {
        tx = x + dx[i];
        ty = y + dy[i];
        if (tx >= 0 && tx <= n+1 && ty >= 0 && ty <= m+1) {
            if (c[tx][ty] == '.')
                tmp++;
        }
    }
    if (tmp >= 3) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> c[i][j];
    for (int i = 0; i <= m+1; i++) {
        c[0][i] = c[n+1][i] = '.';
    }
    for (int i = 0; i <= n+1; i++) {
        c[i][0] = c[i][m+1] = '.';
    }
    int up = n, dw = 0, l = m, r = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == 'X') {
                if (check(i, j))
                    ans[i][j] = '.';
                else {
                    ans[i][j] = 'X';
                    up = min(up, i);
                    dw = max(dw, i);
                    l = min(l, j);
                    r = max(r, j);
                }
            } else {
                ans[i][j] = '.';
            }
        }
    }
    for (int i = up; i <=dw; i++) {
        for (int j = l; j <= r; j++)
            cout << ans[i][j];
        cout << endl;
    }
    return 0;
}
