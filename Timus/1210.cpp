/*******************************************************************************
	> File Name: 1210.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Wed Jun  3 01:10:51 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
const int INF = 1e9;

int n, cnt, k;
int dis[MAXN], d[MAXN];

int main(int argc, char* argv[]) {
    cin >> n;
    cnt = 0;
    dis[1] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            d[j] = INF;
            int u, w;
            cin >> u;
            while (u != 0) {
                cin >> w;
                d[j] = min(d[j], dis[u] + w);
                cin >> u;
            }
        }
        memcpy(dis, d, MAXN * sizeof(int));
        if (i < n-1) {
            char c;
            cin >> c;
        }
    }
    int ans = INF;
    for (int i = 1; i <= k; ++i)
        ans = min(ans, dis[i]);
    cout << ans << endl;
    return 0;
}
