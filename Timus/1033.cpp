/*******************************************************************************
	> File Name: 1033.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon May 11 16:16:01 2015
*******************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 40;

char mp[MAXN][MAXN];
bool vis[MAXN][MAXN] = {0};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

queue<pair<int, int> > Q;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", &mp[i]);
    Q.push(make_pair(0, 0));
    Q.push(make_pair(n-1, n-1));
    vis[0][0] = true;
    vis[n-1][n-1] = true;
    int ans = 0;
    while (!Q.empty()) {
        pair<int, int> src;
        src = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = src.first + dx[i];
            int ty = src.second + dy[i];
            if (!vis[tx][ty]) {
                if ((tx < 0 || tx >= n || ty < 0 || ty >= n) || mp[tx][ty] == '#') {
                    ans++;
                } else if (mp[tx][ty] == '.') {
                    vis[tx][ty] = true;
                    Q.push(make_pair(tx, ty));
                }
            }
        }
    }
    ans -= 4;
    cout << ans * 9 << endl;
    return 0;
}
