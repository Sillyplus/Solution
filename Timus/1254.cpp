#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

const double r2 = sqrt(2.0);

int n, m, k;
double vv;
char c[80][80];
int bomb[1010][2];
int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};

vector<pair<int, double> > v[6000];
double dist[6000];
bool q[6000];
queue<int> que;

bool ck(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    return true;
}

void addE(int x, int y) {
    for (int t = 0; t < 4; t++) {
        int xx = x + dx[t], yy = y + dy[t];
        if (ck(xx, yy) && (c[xx][yy] == '.')) {
            v[x*m+y].push_back(make_pair(xx*m+yy, 1));
        }
    }
    for (int t = 4; t < 8; t++) {
        int xx = x + dx[t], yy = y + dy[t];
        if (ck(xx, yy) && (c[xx][yy] == '.')) {
            v[x*m+y].push_back(make_pair(xx*m+yy, r2));
        }
    }
}

void spfa(int src) {
    for (int i = 0; i < 6000; i++) dist[i] = 10000000;
    memset(q, false, sizeof(q));
    dist[src] = 0;
    while (!que.empty()) que.pop();
    que.push(src);
    q[src] = true;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int i = 0; i < v[u].size(); i++)
            if (dist[u] + v[u][i].second < dist[v[u][i].first]) {
                dist[v[u][i].first] = dist[u] + v[u][i].second;
                if (!q[v[u][i].first]) {
                    q[v[u][i].first] = true;
                    que.push(v[u][i].first);
                }
            }
        q[u] = false;
    }
}

int main() {
    int x, y, tx, ty;
    cin >> m >> n >> k >> vv;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    cin >> y >> x;
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &ty, &tx);
        bomb[i][0] = tx-1;
        bomb[i][1] = ty-1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == '.') {
                addE(i, j);
            }
        }
    }

    double ans = 0;
    x--; y--;
    for (int i = 0; i < k; i++) {
        spfa(x*m+y);
        int num = bomb[i][0]*m + bomb[i][1];
        if (dist[num] < 10000000) {
            ans += dist[num];
            x = bomb[i][0];
            y = bomb[i][1];
        }
    }

    //cout << ans << endl;
    ans = ans / vv;
    printf("%.2f\n", ans);
    return 0;
}
