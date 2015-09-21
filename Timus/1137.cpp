/*******************************************************************************
	> File Name: 1137.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri Sep 11 15:14:42 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;

vector<int> g[MAXN];
vector<bool> vis[MAXN];

void dfs(int x) {
    for (int i = 0; i < g[x].size(); ++i) {
        if (!vis[x][i]) {
            vis[x][i] = true;
            dfs(g[x][i]);
        }
    }
    cout << " " << x;
}

int main(int argc, char* argv[]) {
    int t, n, k, x, tmp;
    cin >> t;
    int ans = 0;
    while (t--) {
        cin >> n >> k;
        ans += n;
        for (int i = 1; i <= n; ++i) {
            cin >> x;
            tmp = x;
            g[x].push_back(k);
            vis[x].push_back(false);
            k = x;
        }
    }
    cout << ans;
    dfs(tmp);
    cout << endl;
    return 0;
}
