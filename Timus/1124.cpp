/*******************************************************************************
	> File Name: 1124.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri Sep 11 13:51:49 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXM = 500 + 10;

int n, m, ans;
int fa[MAXM], cc[MAXM];
bool vis[MAXM];
vector<int> g[MAXM];

void dfs(int now, int st) {
    for (int i = 0; i < g[now].size(); ++i) {
        if (fa[g[now][i]] == g[now][i]) {
            fa[g[now][i]] = st;
            dfs(g[now][i], st);
        }
    }
}

int main(int argc, char* argv[]) {
    cin >> m >> n;
    ans = 0;
    int x;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> x;
            if (x != i) {
                g[i].push_back(x);
                ans++;
            }
        }
        fa[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        if (fa[i] == i) {
            dfs(i, i);
        }
    }
    memset(cc, 0, sizeof(cc));
    for (int i = 1; i <= m; ++i) {
        cc[fa[i]]++;
    }
    for (int i = 1; i <= m; ++i) {
        if (cc[i] > 1)
            ans++;
    }
    ans = (ans-1) < 0 ? 0 : ans-1;
    cout << ans << endl;
    return 0;
}
