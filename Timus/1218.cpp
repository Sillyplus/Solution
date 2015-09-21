/*******************************************************************************
	> File Name: 1218.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat Sep 12 02:31:02 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 210;

int n;
map<int, string> mp;
vector<int> g[MAXN];
bool vis[MAXN];

struct pt{
    int a, b, c;
} f[MAXN];

bool cp(int x, int y) {
    int tmp = 0;
    if (f[x].a > f[y].a) tmp++;
    if (f[x].b > f[y].b) tmp++;
    if (f[x].c > f[y].c) tmp++;
    if (tmp >= 2) return true;
    return false;
}

int bfs(int x) {
    int ret = 1;
    queue<int> q;
    q.push(x);
    vis[x] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < g[u].size(); ++i) {
            int nt = g[u][i];
            if (!vis[nt]) {
                ret++;
                vis[nt] = true;
                q.push(nt);
            }
        }
    }
    return ret;
}

int main(int argc, char* argv[]) {
    cin >> n;
    int a, b, c;
    string s;
    for (int i = 1; i <= n; ++i) {
        cin >> s >> f[i].a >> f[i].b >> f[i].c;
        mp[i] = s;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            if (cp(i, j)) {
                g[i].push_back(j);
            } else {
                g[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        memset(vis, false, sizeof(vis));
        if (bfs(i) == n) {
            cout << mp[i] << endl;
        }
    }
    return 0;
}
