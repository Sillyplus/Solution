#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int MN = 1010;

struct girl{
    int d, w;
};

int n, v;
girl a[MN];
int f[MN][MN][2];

int main() {
    cin >> n >> v;
    for (int i = 1; i <= n; i++)
        cin >> a[i].d >> a[i].w;
    for (int i = 1; i <= n; i++)
        a[i].w += a[i-1].w;
    f[v][v][0] = f[v][v][1] = 0;
    for (int i = v-1; i >= 1; i--) {
        f[i][v][0] = f[i+1][v][0]+(a[i+1].d-a[i].d)*(a[n].w-a[v].w+a[i].w);
        f[i][v][1] = f[i][v][0]+(a[v].d-a[i].d)*(a[n].w-a[v].w+a[i-1].w);
    }
    for (int i = v+1; i <= n; i++) {
        f[v][i][1] = f[v][i-1][1]+(a[i].d-a[i-1].d)*(a[n].w-a[i-1].w+a[v-1].w);
        f[v][i][0] = f[v][i][1]+(a[i].d-a[v].d)*(a[n].w-a[i].w+a[v-1].w);
    }
    for (int i = v-1; i >= 1; i--)
        for (int j = v+1; j <= n; j++) {
            f[i][j][0] = min(f[i+1][j][0]+(a[i+1].d-a[i].d)*(a[n].w-a[j].w+a[i].w),
                            f[i+1][j][1]+(a[j].d-a[i].d)*(a[n].w-a[j].w+a[i].w));
            f[i][j][1] = min(f[i][j-1][1]+(a[j].d-a[j-1].d)*(a[n].w-a[j-1].w+a[i-1].w),
                            f[i][j-1][0]+(a[j].d-a[i].d)*(a[n].w-a[j-1].w+a[i-1].w));
        }
    cout << min(f[1][n][0], f[1][n][1]) << endl;
    return 0;
}
