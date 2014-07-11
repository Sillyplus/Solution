#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

int a[110][110] = {0};
int f[110] = {0};
bool l[110];

vector< set<int> > v(110);
set<int>::iterator its;

int main() {
    int n, m, k;
    memset(l, false, sizeof(l));
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if ((f[j] != 0) || (a[j][i] == 0)) continue;
            if (l[a[j][i]])
                f[j] = i;
            else
                v[a[j][i]].insert(j);
        }
        for (int j = 1; j <= k; j++) {
            if (v[j].size() > 1) {
                for (its = v[j].begin(); its != v[j].end(); its++)
                    f[*its] = i;
                l[j] = true;
            }
            v[j].clear();
        }
    }
    for (int i = 1; i<= n; i++) cout << f[i] << endl;
    return 0;
}
