/*******************************************************************************
	> File Name: 1934.cpp
	> Author: sillyplus
	> Mail: oi_boy@sina.cn
	> Created Time: Fri Sep 11 09:49:55 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int INF = 1e9;

int n, m, s, t, h;
bool vis[MAXN];
int pre[MAXN], dis[MAXN], head[MAXN];
double p[MAXN];

struct edge{
    int v, next;
    double p;
} e[MAXN * 2];

vector<int> path;

void addEdge(int u, int v, double pob) {
    e[h].v = v;
    e[h].p = pob;
    e[h].next = head[u];
    head[u] = h++;
}

void spfa() {
    memset(vis, false, sizeof(vis));
    memset(pre, 0, sizeof(pre));
    for (int i = 0; i <= n; ++i) {
        p[i] = 0;
        dis[i] = INF;
    }
    queue<int> q;
    dis[s] = 0;
    q.push(s);
    vis[s] = true;
    p[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                pre[v] = u;
                p[v] = p[u] * e[i].p; 
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            } else if (dis[v] == dis[u] + 1) {
                if (p[v] < p[u] * e[i].p) {
                    pre[v] = u;
                    p[v] = p[u] * e[i].p;
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    cin >> n >> m;
    cin >> s >> t;
    int u, v, pp;
    h = 0;
    memset(head, -1, sizeof(head));
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &pp);
        addEdge(u, v, 1-pp/100.0);
        addEdge(v, u, 1-pp/100.0);
    }
    spfa();
    printf("%d %.9f\n", dis[t] + 1, 1.0 - p[t]);
    int now = t;
    while (now != 0) {
        path.push_back(now);
        now = pre[now];
    }
    for (int i = path.size() - 1; i >= 0; --i) {
        printf("%d ", path[i]);
    }
    cout << endl;
    return 0;
}
