/*******************************************************************************
	> File Name: 1982.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Jun  2 13:37:34 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;

struct edge {
    int w, u, v;
    edge(int w, int u, int v) : w(w), u(u), v(v) {}
};

bool operator < (const edge &a, const edge &b) {
    return a.w < b.w;
}

vector<edge> e;

int a[MAXN][MAXN], x[MAXN], fa[MAXN];
int n, k;

int getfa(int x) {
    return (fa[x] == x ? x : fa[x] = getfa(fa[x]));
}

int main(int argc, char* argv[]) {
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            if (i != j) {
                e.push_back(edge(a[i][j], i, j));
            }
        }
    }
    sort(e.begin(), e.end());
    for (int i = 1; i <= n+1; ++i)
        fa[i] = i;
    for (int i = 0; i < k; ++i) {
        fa[x[i]] = n+1;
    }
    int ans = 0;
    int cnt = n-k;
    for (int i = 0; i < e.size(); ++i) {
        int t1 = getfa(e[i].u);
        int t2 = getfa(e[i].v);
        if (t1 != t2) {
            fa[t1] = fa[t2];
            ans += e[i].w;
            cnt--;
            if (cnt == 0)
                break;
        }
    }
    cout << ans << endl;
    return 0;
}
