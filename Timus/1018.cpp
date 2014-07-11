#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int MN = 110;

vector<pair<int,int> > a[MN];
int f[MN][MN] = {0};
int p[MN] = {0};
int n, q;


int dp(int v, int fa) {
    p[v] = 1;
    for (int i = 0; i < a[v].size(); i++) {
        int u = a[v][i].first;
        if (u == fa) continue;
        p[v] += dp(u, v);
    }

    for (int i = 0; i < a[v].size(); i++) {
        int u = a[v][i].first;
        int w = a[v][i].second;
        if (u == fa) continue;
        for (int j = p[v]; j > 0; j--) {
            for (int k = 1; k < j && k <= p[u]; k++) {
                f[v][j] = max(f[v][j], f[v][j-k]+f[u][k]+w);
            }
        }
    }

    return p[v];
}

int main() {
    cin >> n >> q;
    int u, v, w;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v >> w;
        a[u].push_back(make_pair(v, w));
        a[v].push_back(make_pair(u, w));
    }
    dp(1, -1);
    cout << f[1][q+1] << endl;
    return 0;
}
