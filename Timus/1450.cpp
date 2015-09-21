/*******************************************************************************
	> File Name: 1450.cpp
	> Author: sillyplus
	> Mail: oi_boy@sina.cn
	> Created Time: Sat Sep 12 02:54:52 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 510;
const int MAXM = 500 * 500;
const int INF = 1e9;

int n, m, s, t;
vector<pair<int, int> > g[MAXN];
queue<int> q;
bool vis[MAXN];
int dis[MAXN];

void spfa() {
    dis[s] = 0;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i].first;
            if (dis[u] + g[u][i].second > dis[v]) {
                dis[v] = dis[u] + g[u][i].second;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        std::scanf("%d%d%d", &u, &v, &w);
        g[u].push_back(make_pair(v, w));
    }
    cin >> s >> t;
    for (int i = 0; i < MAXN; ++i)
        dis[i] = -INF;
    memset(vis, false, sizeof(vis));
    spfa();
    if (dis[t] == -INF) {
        cout << "No solution" << endl;
    } else {
        cout << dis[t] << endl;
    }
    return 0;
}
