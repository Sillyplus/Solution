#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MN = 110;

int map[MN][MN] = {0};
bool f[MN] = {0};

int n, m, s, root;
bool flag = false;

void dfs(int rt, int ds) {
    if (flag) return;
    if (ds >= s) {
        flag = true;
        return;
    }
    for (int i = 1; i <= m; i++) {
        if (!f[i] && map[rt][i]) {
            int tmp = map[rt][i];
            map[rt][i] = map[i][rt] = 0;
            f[i] = true;
            if (i == root) {
                flag = true;
                return;
            }
            dfs(i, ds+tmp);
            map[rt][i] = map[i][rt] = tmp;
            f[i] = false;
            if (flag) return;
        }
    }
}

int main() {
    cin >> m >> n >> s;
    int u, v, dis;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &u, &v, &dis);
        if (!map[u][v]) {
            map[u][v] = map[v][u] = dis;
        } else {
            flag = true;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (flag) break;
        memset(f, false, sizeof(f));
        root = i;
        dfs(i, 0);
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
