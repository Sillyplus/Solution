#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int MN = 110;
const int INF = 1e8;

int n, m, num, ans;
int mp[MN][MN], dis[MN][MN], pre[MN][MN];
int path[MN];

void get_path(int a, int b) {
    if (pre[a][b]) {
        get_path(a, pre[a][b]);
        get_path(pre[a][b], b);
    } else {
        path[num++] = a;
    }
}

bool check(int i, int j, int k) {
    if (i != j && j != k && k != i)
        return true;
    else
        return false;
}

int main() {
    while (scanf("%d", &n) && (n != -1)) {
        scanf("%d", &m);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                mp[i][j] = INF;
                dis[i][j] = INF;
                pre[i][j] = 0;
            }
        }
        int a, b, l;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &l);
            mp[a][b] = min(mp[a][b], l);
            mp[b][a] = dis[a][b] = dis[b][a] = mp[a][b];
        }
        ans = INF;
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i < k; i++)
                for (int j = i+1; j < k; j++) {
                    int tmp = dis[i][j] + mp[j][k] + mp[k][i];
                    if (check(i, j, k) && (tmp < ans)) {
                        ans = tmp;
                        num = 0;
                        get_path(i, j);
                        path[num++] = j;
                        path[num++] = k;
                    }
                }

            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++) {
                    int tmp = dis[i][k] + dis[k][j];
                    if (check(i, j, k) && (dis[i][j] > tmp)) {
                        dis[i][j] = tmp;
                        pre[i][j] = k;
                    }
                }
        }
        if (ans == INF) {
            cout << "No solution." << endl;
        } else {
            for (int i = 0; i < num; i++)
                printf("%d ", path[i]);
            cout << endl;
        }
    }
    return 0;
}
