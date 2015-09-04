/*******************************************************************************
	> File Name: 1109.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat Aug 29 16:35:45 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

vector<int> g[MAXN];
int from[MAXN], n, m, k, tot;
bool use[MAXN];

bool match(int x) {
    for (int i = 0; i < g[x].size(); ++i) {
        if (!use[g[x][i]]) {
            use[g[x][i]] = true;
            if (from[g[x][i]] == -1 || match(from[g[x][i]])) {
                from[g[x][i]] = x;
                return true;
            }
        }
    }
    return false;
}

int hungary() {
    tot = 0;
    memset(from, 255, sizeof(from));
    for (int i = 1; i <= m; ++i) {
        memset(use, false, sizeof(use));
        if (match(i))
            tot++;
    }
    return tot;
}

int main(int argc, char* argv[]) {
    cin >> m >> n >> k;
    int u, v;
    for (int i = 0; i < k; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    cout << (m + n - hungary()) << endl; 
    return 0;
}
