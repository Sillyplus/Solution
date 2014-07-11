#include <iostream>
#include <string>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int MN = 20;

struct pt{
    int x, y;
};

int n, ans, vx, vy;
bool vis[MN][MN];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
pt a[MN*MN];
char c[] = {'R', 'T', 'L', 'B'}, b[MN];
queue<pt> q;

bool comp(const pt &pa, const pt &pb) {
    if (pa.x != pb.x) return pa.x < pb.x;
    return pa.y < pb.y;
}

void bfsa() {
    pt now, next;
    string dir;
    while (!q.empty()) {
        now = q.front();
        a[ans] = now;
        cin >> dir;
        for (int i = 0; i < dir.length() - 1; i++) {
            char tc = dir[i];
            int j;
            for (j = 0; j < 4; j++) {
                if (c[j] == tc) break;
            }
            next.x = now.x + dx[j];
            next.y = now.y + dy[j];
            q.push(next);
        }
        q.pop();
        ans++;
    }
}

void bfsb() {
    pt now, next;
    while (!q.empty()) {
        now = q.front();
        for (int i = 0; i < 4; i++) {
            int tx = now.x + dx[i];
            int ty = now.y + dy[i];
            if (vis[tx][ty] == 1) {
                cout << c[i];
                vis[tx][ty] = 0;
                next.x = tx;
                next.y = ty;
                q.push(next);
            }
        }
        ans++;
        if (ans != n)
            cout << ",\n";
        else
            cout << ".\n";
        q.pop();
    }
}

int main() {
    string s;
    getline(cin, s);
    memset(vis, 0, sizeof(vis));
    pt k;
    if (s.find(' ') != string::npos) {
        s.copy(b, s.find(' '), 0);
        vx = atoi(b);
        s.copy(b, 100, s.find(' ') + 1);
        vy = atoi(b);
        pt k;
        k.x = vx;
        k.y = vy;
        q.push(k);
        bfsa();
        sort(a, a+ans, comp);
        cout << ans << endl;
        for (int i = 0; i < ans; i++)
            cout << a[i].x << ' ' << a[i].y << endl;
    } else {
        n = atoi(s.c_str());
        for (int i = 0; i < n; i++) {
            cin >> k.x >> k.y;
            vis[k.x][k.y] = 1;
            if (i == 0) {
                q.push(k);
                cout << k.x << ' ' << k.y << endl;
                vis[k.x][k.y] = 0;
            }
        }
        ans = 0;
        bfsb();
    }
    return 0;
}
