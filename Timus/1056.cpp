#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const int MN = 10010;

vector <int> a[MN];
bool vt[MN];
int f[MN];

int n, k, l, v;

void dfs(int x, int pr, int de) {
    vt[x] = true;
    f[x] = pr;
    if (de > l) {
        l = de;
        v = x;
    }
    for (int i = 0; i < a[x].size(); i++) {
        int ch = a[x][i];
        if (vt[ch]) continue;
        dfs(ch, x, de+1);
    }
}

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> k;
        a[k].push_back(i);
        a[i].push_back(k);
    }
    v = l = 0;
    memset(vt, false, sizeof(vt));
    dfs(1, 0, 1);
    memset(vt, false, sizeof(vt));
    l = 0;
    dfs(v, 0, 1);
    for (int i = 1; i < l/2; i++)
        v = f[v];
    if (l % 2)
        cout << f[v] << endl;
    else
        cout << min(v, f[v]) << " " << max(v, f[v]) << endl;
    return 0;
}
