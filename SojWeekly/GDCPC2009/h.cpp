#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

const int MN = 100010;

struct st{
    int l, r;
    int p;
};

int a[MN], to[MN], next[MN], head[MN], dx[MN];
int l[MN], r[MN];
bool vis[MN];
st b[MN];
int totalm, cnt;

void add(int x, int y) {
    int p = ++totalm;
    to[p] = y;
    next[p] = head[x];
    head[x] = p;
}

void dfs(int x){
    l[x] = ++cnt;
    vis[x] = 1;
    for (int i = head[x]; i != 0; i = next[i])
        if (!vis[to[i]])
            dfs(to[i]);
    r[x] = ++cnt;
}

int

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(vis, false, sizeof(vis));
        cin >> n >> m;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i < n; i++) {
            scanf("%d%d", &b[i].l, &b[i].r);
            add(b[i].l, b[i].r);
            add(b[i].r, b[i].l);
        }
        dfs(1);
        int x, w;
        for (int i = 0; i < m; i++) {
            cin >> s;
            if (s == "CHANGE") {
                scanf("%d%d", &x, &w);

            } else {
                scanf("%d", &x);

            }
        }
    }
    return 0;
}
