/*******************************************************************************
	> File Name: 1205.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Thu Jun 11 15:15:56 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 210;
const double INF = 1e10;

struct point{
    double x, y;
} p[MAXN];

double cost[MAXN][MAXN];
double foot, metro;

int mid[MAXN][MAXN];
int n;

vector<int> path;

void route(int x, int y) {
    if (mid[x][y] != -1) {
        route(x, mid[x][y]);
        route(mid[x][y], y);
    } else {
        path.push_back(x);
    }
}

double dis(int u, int v) {
    return sqrt(pow(p[u].x - p[v].x, 2) + pow(p[u].y - p[v].y, 2));
}

int main(int argc, char* argv[]) {
    cin >> foot >> metro;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i].x >> p[i].y;
    }
    int u, v;
    memset(cost, 0, sizeof(cost));
    while (cin >> u >> v) {
        if (u == 0 && v == 0) break;
        cost[v][u] = cost[u][v] = dis(u, v) / metro;
    }

    cin >> p[0].x >> p[0].y;
    n++;
    cin >> p[n].x >> p[n].y;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (cost[i][j] == 0) {
                cost[i][j] = dis(i, j) / foot;
            }
        }
    }

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            mid[i][j] = -1;

    for (int k = 0; k <= n; ++k) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (cost[i][j] > cost[i][k] + cost[k][j]) {
                    cost[i][j] = cost[i][k] + cost[k][j];
                    mid[i][j] = k;
                }
            }
        }
    }

    printf("%.7f\n", cost[0][n]);
    route(0, n);
    cout << path.size() - 1;
    for (int i = 1; i < path.size(); ++i)
        cout << " " << path[i];
    cout << endl;
    return 0;
}
