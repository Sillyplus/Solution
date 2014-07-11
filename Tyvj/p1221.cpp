//
//  main.cpp
//  p1221
//
//  Created by Silly on 14-2-9.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int MN = 1010;

vector<pair<int, int>> g[MN];
int dist[MN] = {0};
bool inQue[MN];
queue<int> que;

int main(int argc, const char * argv[])
{
    int n, m, l, a, b, c;
    cin >> n >> m >> l;
    for (int i = 0; i < l ; i++) {
        scanf("%d%d%d", &a, &b, &c);
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    
    memset(dist, 0x7f, sizeof(dist));
    dist[m] = 0;
    que.push(m);
    inQue[m] = true;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int i = 0; i < g[u].size(); i++) {
            if (dist[u] + g[u][i].second < dist[g[u][i].first]) {
                dist[g[u][i].first] = dist[u] + g[u][i].second;
                if (!inQue[g[u][i].first]) {
                    inQue[g[u][i].first] = true;
                    que.push(g[u][i].first);
                }
            }
        }
        inQue[u] = false;
    }
    int ans = 0;
    for (int i = 1 ; i <= n; i++) {
        if (dist[i] == 2139062143) {
            cout << "Sth wrong." << endl;
            return 0;
        }
        ans += dist[i];
    }
    cout << ans << " M(s) are needed." << endl;
    return 0;
}

