#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int MN = 210;
const int INF = 1000000000;

int n;
int b[MN], dis[MN][MN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d", &dis[i][j]);
            if (dis[i][j] == 0)
                dis[i][j] = INF;
        }
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
        }
    }
    int ans = INF, tmp, an;
    for (int i = 1; i <= n; i++) {
        tmp = 0;
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                tmp += dis[i][j] * b[j];
            }
        }
        if (tmp < ans) {
            an = i;
            ans = tmp;
        }
    }
    cout << an << endl << ans << endl;
    return 0;
}
