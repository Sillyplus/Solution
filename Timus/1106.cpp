/*******************************************************************************
	> File Name: 1106.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sun Aug 23 19:52:32 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MN = 110;

int n, k;
vector<int> g[MN];
int vit[MN];

void dfs(int x, int color) {
    vit[x] = color;
    color = (color == 1 ? 2:1);
    for (int i = 0; i < g[x].size(); i++)
        if (!vit[g[x][i]]) dfs(g[x][i], color);
}

int main(int argc, char* argv[]) {
    memset(vit, 0, sizeof(vit));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        while (k) {
            g[i].push_back(k);
            scanf("%d", &k);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vit[i]) dfs(i, 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (!vit[i]) {
            cout << 0 << endl;
            return 0;
        } else if (vit[i] == 1) ans++;
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        if (vit[i] == 1) cout << i << ' ';
    cout << endl;
    return 0;
}
