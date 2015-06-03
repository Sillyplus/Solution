/*******************************************************************************
	> File Name: 1069.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Wed Jun  3 07:57:27 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 7500 + 10;

int a[MAXN], vis[MAXN];
vector<int> ans[MAXN];
set<int> leaf;

int main(int argc, char* argv[]) {
    int n = 0;
    memset(vis, 0, sizeof(vis));
    while (scanf("%d", &a[n++]) == 1) {
        vis[a[n-1]]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0) leaf.insert(i);
    }
    for (int i = 0; i < n-1; ++i) {
        int lf = *(leaf.begin());
        leaf.erase(lf);
        ans[a[i]].push_back(lf);
        ans[lf].push_back(a[i]);
        vis[a[i]]--;
        if (vis[a[i]] == 0) 
            leaf.insert(a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        cout << i << ":";
        sort(ans[i].begin(), ans[i].end());
        for (int j = 0; j < ans[i].size(); ++j)
            cout << " " << ans[i][j];
        cout << endl;
    }
    return 0;
}
