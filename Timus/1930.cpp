/*******************************************************************************
	> File Name: 1930.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Thu Jun 11 12:41:51 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;

vector<pair<int, int> > e[MAXN];
queue<int> q;

int dis[MAXN][2];
bool flag[MAXN];

int main(int argc, char* argv[]) {
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        e[u].push_back(make_pair(v, 1));
        e[v].push_back(make_pair(u, -1));
    }
    int s, t;
    cin >> s >> t;
    memset(dis, 0x7f, sizeof(dis));
    memset(flag, false, sizeof(flag));
    dis[s][0] = dis[s][1] = 0;
    q.push(s);
    flag[s] = true;
    while (!q.empty()) {
        int src = q.front();
        q.pop();
        for (int i = 0; i < e[src].size(); ++i) {
            int dst = e[src][i].first;
            int m1 = min(dis[src][0], dis[src][1] + 1);
            int m2 = min(dis[src][0] + 1, dis[src][1]);
            bool tag = false;
            if (e[src][i].second == 1) {
                if (m1 < dis[dst][0]) {
                    dis[dst][0] = m1;
                    tag = true;
                }
            } else {
                if (m2 < dis[dst][1]) {
                    dis[dst][1] = m2;
                    tag = true;
                }
            }
            if (tag && flag[dst] == false) {
                flag[dst] = true;
                q.push(dst);
            }
        }
        flag[src] = false;
    }
    cout << min(dis[t][0], dis[t][1]) << endl;
    return 0;
}
