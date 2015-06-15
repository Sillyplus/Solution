/*******************************************************************************
	> File Name: 1039.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon Jun 15 23:21:47 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 6e3 + 10;
const int INF = -1e8;

int f[MAXN][2];
int c[MAXN], root[MAXN];
vector<int> guy[MAXN];

void getAns(int rt, int flag) {
    if (f[rt][flag] != INF) return;
    if (guy[rt].size() == 0) {
        f[rt][0] = 0;
        f[rt][1] = c[rt];
        return;
    }
    int tmp1 = 0, tmp2 = 0;
    for (int i = 0; i < guy[rt].size(); ++i) {
        int nt = guy[rt][i];
        if (f[nt][0] == INF) getAns(nt, 0);
        if (f[nt][1] == INF) getAns(nt, 1);
        tmp1 += max(f[nt][0], f[nt][1]);
        tmp2 += f[nt][0];
    }
    f[rt][0] = tmp1;
    f[rt][1] = tmp2 + c[rt];
}

int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        f[i][0] = f[i][1] = INF;
    }

    int l, r;
    memset(root, 0, sizeof(root));
    while (scanf("%d%d", &l, &r) == 2 && (l || r)) {
        root[l] = r;
        guy[r].push_back(l);
    }

    int ans = INF; 
    for (int i = 1; i <= n; ++i) {
        getAns(i, 0);
        getAns(i, 1);
        ans = max(ans, max(f[i][0], f[i][1]));
    }

    cout << ans << endl;

    return 0;
}
