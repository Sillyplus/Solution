/*******************************************************************************
	> File Name: 1742.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Sep  1 16:11:49 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, dfs_tag, ans_min, ans_max; 
int du[MAXN], dfn[MAXN], low[MAXN], nt[MAXN], scc_n[MAXN], num[MAXN];
vector<int> Stack;
bool inStack[MAXN];

void tarjan(int x) {
    dfn[x] = low[x] = ++dfs_tag;
    Stack.push_back(x);
    inStack[x] = true;
    if (nt[x] != 0) {
        int v = nt[x];
        if (dfn[v] == 0) {
            tarjan(v);
            low[x] = min(low[x], low[v]);
        } else if (inStack[v]) {
            low[x] = min(low[x], dfn[v]);
        }
    }
    if (dfn[x] == low[x]) {
        ans_max++;
        int v;
        do {
            v = Stack.back();
            Stack.pop_back();
            inStack[v] = false;
            scc_n[v] = ans_max;
        } while (v != x);
    }
}

int main(int argc, char* argv[]) {
    cin >> n;
    int v;
    memset(du, 0, sizeof du);
    for (int i = 1; i <= n; ++i) {
        cin >> v;
        nt[i] = v;
        du[v]++;
    }
    ans_min = ans_max = 0;
    memset(dfn, 0, sizeof dfn);
    dfs_tag = 0;
    for (int i = 1; i <= n; ++i) {
        if (dfn[i] == 0)
            tarjan(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (scc_n[i] != scc_n[nt[i]]) 
            num[scc_n[nt[i]]]++;
    }
    for (int i = 1; i <= ans_max; ++i) {
        if (num[i] == 0) 
            ans_min++;
    }
    cout << ans_min << " " << ans_max << endl;
    return 0;
}
