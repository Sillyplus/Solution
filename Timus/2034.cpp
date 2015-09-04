/*******************************************************************************
	> File Name: 2034.cpp
	> Author: sillyplus
	> Mail: oi_boy@sina.cn
	> Created Time: Mon Aug 31 14:53:47 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int INF = 1e9;

vector<pair<int, int> > g[MAXN];
int dist[MAXN];
bool inQue[MAXN], visit[MAXN];
queue<int> que;

struct pnd{
    int dis, mds;
} stt[MAXN];

int n, m, src, des, r;

void spfa() {
    memset(dist, 63, sizeof(dist));
    memset(inQue, false, sizeof(inQue));
    dist[src] = 0;
    while (!que.empty()) que.pop();
    que.push(src);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int i = 0; i < g[u].size(); ++i) {
            if (dist[u] + g[u][i].second < dist[g[u][i].first]) {
                dist[g[u][i].first] = dist[u] + g[u][i].second;
                if (!inQue[g[u][i].first]) {
                    inQue[g[u][i].first] = true;
                    que.push(g[u][i].first);
                }
            }
        }
        inQue[u] = false;
    }
}

void bfs() {
    while (!que.empty()) que.pop();
    for (int i = 0; i <= n; ++i) {
        stt[i].dis = INF;
        stt[i].mds = dist[i];
    }
    memset(visit, false, sizeof(visit));
    que.push(src);
    visit[src] = true;
    stt[src].dis = 0;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i].first;
            if (!visit[v]) {
                que.push(v);
                visit[v] = true;
                stt[v].mds = min(stt[v].mds, stt[u].mds);
                stt[v].dis = stt[u].dis + 1;
            } else {
                if (stt[v].dis == (stt[u].dis + 1))
                    stt[v].mds = max(stt[v].mds, min(stt[u].mds, dist[v]));
            }
        }
    }
}

int main(int argc, char* argv[]) {
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        g[u].push_back(make_pair(v, 1));
        g[v].push_back(make_pair(u, 1));
    }
    int s, t;
    cin >> s >> t >> r;
    src = r;
    spfa();
    src = s;
    des = t;
    bfs();
    cout << stt[t].mds << endl;
    return 0;
}
