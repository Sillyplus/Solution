/*******************************************************************************
	> File Name: 1080.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Jun  2 14:12:06 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;

int n, x;
int f[MAXN];
bool mp[MAXN][MAXN];

bool bfs(int x) {
    bool ret = true;
    f[x] = 0;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i) if (mp[t][i])
            if (f[i] == -1) {
                f[i] = f[t] ^ 1;
                q.push(i);
            } else if (f[i] != (f[t] ^ 1)) {
                return false;
            }
    }
    return ret;
}

int main(int argc, char* argv[]) {
    cin >> n;
    for (int i = 0; i <= n; ++i)
        f[i] = -1;
    memset(mp, false, sizeof(mp));
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        while (x != 0) {
            mp[x][i] = mp[i][x] = true;
            cin >> x;
        }
    }
    bool flag;
    for (int i = 1; i <= n; ++i) {
        if (f[i] == -1) {
            flag = bfs(i);
            if (flag == false) break;
        }
    }
    if (flag) {
        for (int i = 1; i <= n; ++i)
            cout << f[i];
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
