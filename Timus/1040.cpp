/*******************************************************************************
	> File Name: 1040.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon Jun 22 14:52:46 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXM = 2500;
const int MAXN = 60;

int n, m, label;
vector<pair<int, int> > g[MAXN];
bool vis[MAXN], vis2[MAXM];
int ans[MAXM];

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

void dfs(int x) {
    for (int i = 0; i < g[x].size(); ++i) {
        int next = g[x][i].second;
        int edge = g[x][i].first;
        if (!vis2[edge]) {
            ans[edge] = ++label;
            vis2[edge] = true;
        }
        if (!vis[next]) {
            vis[next] = true;
            dfs(next);
        }
    }
}

int main(int argc, char* argv[]) {
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        g[u].push_back(make_pair(i, v));
        g[v].push_back(make_pair(i, u));
    }
    label = 0;
    memset(vis, false, sizeof(vis));
    memset(vis2, false, sizeof(vis2));
    memset(ans, 0, sizeof(ans));
    vis[1] = true;
    dfs(1);
    cout << "YES" << endl;
    for (int i = 1; i < m; ++i)
        cout << ans[i] << " ";
    cout << ans[m] << endl;
    return 0;
}
