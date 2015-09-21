/*******************************************************************************
	> File Name: 1160.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat Sep 12 01:21:57 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;
const int MAXM = 2e4;

int n, m, fa[MAXN], c[MAXN];

struct edge{
    int u, v, w;
};

edge e[MAXM];
vector<edge> ans;

bool comp(const edge &a, const edge &b) {
    return a.w < b.w;
}

int get(int x) {
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}

void putAns() {
    int sz = ans.size();
    cout << ans[sz-1].w << endl;
    cout << sz << endl;
    for (int i = 0; i < sz; ++i) {
        cout << ans[i].u << " " << ans[i].v << endl;
    }
}

int main(int argc, char* argv[]) {
    cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        e[i].u = u;
        e[i].v = v;
        e[i].w = w;
    }
    sort(e, e + m, comp);
    for (int i = 1; i <= n; ++i)
        fa[i] = i, c[i] = 1;
    int f1, f2;
    for (int i = 0; i < m; ++i) {
        f1 = get(e[i].u);
        f2 = get(e[i].v);
        if (f1 != f2) {
            fa[f2] = f1;
            c[f1] += c[f2];
            ans.push_back(e[i]);
            if (c[f1] >= n) {
                putAns();
                return 0;
            }
        }
    }
    return 0;
}
