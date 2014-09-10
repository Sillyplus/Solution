//
//  main.cpp
//  p1424
//
//  Created by Silly on 14-4-1.
//  Copyright (c) 2014年 Silly. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MN = 10010;

vector<int> g[MN];
int du[MN], l[MN];
int n, m;

bool toposort(){
    memset(du, 0, sizeof(du));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            du[g[i][j]]++;
        }
    }
    int tot = 0;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (!du[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        l[tot++] = x;
        for (int j = 0; j < g[x].size(); j++) {
            int t = g[x][j];
            du[t]--;
            if (!du[t]) {
                q.push(t);
            }
        }
    }
    if (tot == n) {
        return  1;
    }
    return 0;
}

int main(int argc, const char * argv[])
{
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            cout << g[i][j] << " " ;
        }
    }
    return 0;
}

