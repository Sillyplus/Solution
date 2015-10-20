/*******************************************************************************
	> file name: 1495.cpp
	> author: sillyplus 
	> mail: oi_boy@sina.cn 
	> created time: tue sep 22 21:44:59 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;

struct pp{
    int x, r, l;
};

int n;
int pre[3][maxn][2];
queue<pp> q;

void putans(int x, int r) {
    if (x == -1) return;
    putans(pre[x][r][0], pre[x][r][1]);
    cout << x;
}

int main(int argc, char* argv[]) {
    cin >> n;
    while (!q.empty()) q.pop();
    memset(pre, -0x7f, sizeof(pre));
    for (int i = 1; i <= 2; ++i) {
        pp t;
        t.x = i;
        t.r = i % n;
        t.l = 1;
        q.push(t);
        pre[t.x][t.r][0] = -1;
    }
    while (!q.empty()) {
        pp u = q.front();
        q.pop();
        if (u.l > 30) {
            break;
        }
        if (u.r == 0) {
            putans(u.x, u.r);
            cout << endl;
            return 0;
        }
        for (int i = 1; i <= 2; ++i) {
            pp v;
            v.x = i;
            v.r = (u.r * 10 + i) % n;
            v.l = u.l + 1;
            if (pre[v.x][v.r][0] >= -1) continue;
            pre[v.x][v.r][0] = u.x;
            pre[v.x][v.r][1] = u.r;
            q.push(v);
        }
    }
    cout << "Impossible" << endl;
    return 0;
}
