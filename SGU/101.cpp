/*******************************************************************************
	> File Name: 101.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat May 30 13:42:05 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 7 + 10;
const int MAXE = 200 + 10;

class Euler { 
    int n, psz, sz;
    struct Edge {
        int v, w;
        Edge *next;
    } epool[MAXE], *e[MAXN], *cur[MAXN];
    
    int deg[MAXN], vec[MAXE];
    bool vis[MAXE];
   
    void dfs(int u) {
        while (cur[u]) {
            Edge *i = cur[u];
            cur[u] = cur[u]->next;
            if (!vis[abs(i->w)]) {
                vis[abs(i->w)] = true;
                dfs(i->v);
                vec[sz++] = i->w;
            }
        }
    }

    public:
    
    void init(int n) {
        this->n = n;
        psz = 0;
        memset(e, 0, sizeof(e));
        memset(deg, 0, sizeof(deg));
    }

    void add_edge(int u, int v, int w) {
        Edge *i = epool + psz++;
        i->v = v;
        i->w = w;
        i->next = e[u];
        e[u] = i;
        if (psz & 1) add_edge(v, u, -w);
        else ++deg[u], ++deg[v];
    }
    
    bool find_path() {
        int s = -1, c = 0;
        for (int i = 0; i < n; ++i) {
            if (deg[i] && s == -1) s = i;
            if (deg[i] & 1) s = i, ++c;
        }
        if (c && c != 2) return false;
        sz = 0;
        memcpy(cur, e, sizeof(cur));
        memset(vis, false, sizeof(vis));
        dfs(s);
        if (sz < psz / 2) return false;
        for (int i = sz-1; i >= 0; --i) {
            printf("%d %c\n", abs(vec[i]), vec[i] > 0 ? '+' : '-');
        }
        return true;
    }

} graph;

int main(int argc, char* argv[]) {
    graph.init(7);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph.add_edge(u, v, i+1);
    }
    if (!graph.find_path())
        puts("No solution\n");
    return 0;
}
