#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int MN = 110;
const int INF = 1e8;

int n, m;
int mp[MN][MN], dis[MN][MN];

int main() {
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                mp[i][j] = dis[i][j] = INF;
            }
        }
        int a, b, l;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &l);
            mp[a][b] = mp[b][a] = min(mp[b][a], l);
            dis[a][b] = dis[b][a] = mp[a][b];
        }
        int ans = INF;
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i < k; i++) {
                for (int j = i+1; j < k; j++) {
                    ans = min(ans, dis[i][j] + mp[j][k] + mp[k][i]);
                }
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        if (ans != INF) {
            cout << ans << endl;
        } else {
            cout << "No solution." << endl;
        }
    }
    return 0;
}
