/*******************************************************************************
	> File Name: 1076.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sun Jun 21 17:01:59 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 160;
const int INF = 1e9;

int n;
int a[MAXN][MAXN], sum[MAXN] = {0};
int w[MAXN][MAXN], lx[MAXN], ly[MAXN], slack[MAXN], link[MAXN];
bool visx[MAXN], visy[MAXN];

bool dfs(int x) {
    visx[x] = true;
    for (int y = 1; y <= n; ++y) {
        if (visy[y]) continue;
        int t = lx[x] + ly[y] - w[x][y];
        if (t == 0) {
            visy[y] = true;
            if (link[y] == -1 || dfs(link[y])) {
                link[y] = x;
                return true;
            }
        } else if (slack[y] > t) {
            slack[y] = t;
        }
    }
    return false;
}

int KM() {
    memset(link, -1, sizeof(link));
    memset(ly, 0, sizeof(ly));
    for (int i = 1; i <= n; ++i) {
        lx[i] = -INF;
        for (int j = 1; j <= n; ++j) {
            lx[i] = max(lx[i], w[i][j]);
        }
    }
    for (int x = 1; x <= n; ++x) {
        for (int i = 1; i <= n; ++i)
            slack[i] = INF;
        while (true) {
            memset(visx, false, sizeof(visx));
            memset(visy, false, sizeof(visy));
            if (dfs(x)) break;
            int d = INF;
            for (int i = 1; i <= n; ++i)
                if (!visy[i] && d > slack[i])
                    d = slack[i];
            for (int i = 1; i <= n; ++i)
                if (visx[i])
                    lx[i] -= d;
            for (int i = 1; i <= n; ++i)
                if (visy[i])
                    ly[i] += d;
                else 
                    slack[i] -= d;
        }
    }
    int ret = 0;
    for (int i = 1; i <= n; ++i) 
        if (link[i] > -1)
            ret += w[link[i]][i];
    return ret;
}

int main(int argc, char* argv[]) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            sum[j] += a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            w[i][j] = -(sum[i] - a[i][j]);
        }
    }
    int ans = -KM();
    cout << ans << endl;
    return 0;
}
