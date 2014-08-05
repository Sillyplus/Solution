#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const int INF = 10000000;

int n;
int a[10][10];
int s[10][10];
int f[20][10][10][10][10];
double ans, tot;

int sum(int x1, int y1, int x2, int y2) {
    int ret;
    ret = s[x2][y2]+s[x1-1][y1-1]-s[x1-1][y2]-s[x2][y1-1];
    return (ret*ret);
}

int dv(int k, int x1, int y1, int x2, int y2) {
    if (k == 1) return sum(x1, y1, x2, y2);
    if (f[k][x1][y1][x2][y2]) return f[k][x1][y1][x2][y2];
    int ver = INF, hor = INF;
    for (int i = x1; i < x2; i++)
        ver = min(ver, min(dv(k-1, x1, y1, i, y2)+sum(i+1, y1, x2, y2),
                        dv(k-1, i+1, y1, x2, y2)+sum(x1, y1, i, y2)));
    for (int i = y1; i < y2; i++)
        hor = min(hor, min(dv(k-1, x1, y1, x2, i)+sum(x1, i+1, x2, y2),
                        dv(k-1, x1, i+1, x2, y2)+sum(x1, y1, x2, i)));
    f[k][x1][y1][x2][y2] = min(ver, hor);
    return f[k][x1][y1][x2][y2];
}

int main() {
    cin >> n;
    tot = 0;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++) {
            cin >> a[i][j];
            tot += a[i][j];
        }
    tot /= n;
    tot = tot*tot;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
    int an;
    an = dv(n, 1, 1, 8, 8);
    //cout << an << endl;
    ans = sqrt(an/(n*1.0)-tot);
    printf("%.3f\n", ans);
    return 0;
}
