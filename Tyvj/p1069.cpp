#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MN = 160;
const double INF = 1000000000.0;

int n;
double ax[MN], ay[MN];
char c[MN][MN];
double dis[MN][MN];
double mdis[MN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ax[i] >> ay[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (c[i][j] == '1') {
                dis[i][j] = sqrt(pow(ax[i]-ax[j],2)+pow(ay[i]-ay[j],2));
            } else
                dis[i][j] = INF;
            if (i == j)
                dis[i][j] = 0;
        }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
    double ans1 = 0, ans2 = INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dis[i][j] != INF && dis[i][j] > mdis[i]) {
                mdis[i] = dis[i][j];
                ans1 = max(ans1, mdis[i]);
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dis[i][j] == INF) {
                double tmp = mdis[i] + mdis[j] + sqrt(pow(ax[i]-ax[j],2)+pow(ay[i]-ay[j],2));
                ans2 = min(ans2, tmp);
            }
    printf("%.6f\n", max(ans1, ans2));
    return 0;
}
