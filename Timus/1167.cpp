/*******************************************************************************
	> File Name: 1167.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Apr 28 00:06:37 2015
*******************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN = 510;
const int INF = 1e9;

int f[MAXN][MAXN];
int sum[MAXN] = {0};
int w[MAXN][MAXN];

int cost(int i, int j) {
    int ret;
    int ones = sum[j] - sum[i-1];
    int zeros = (j-i+1) - ones;
    ret = ones * zeros;
    return ret;
}

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i-1];
    }

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            w[i][j] = cost(i, j);
    
    memset(f, 0x1f, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            for (int x = 1; x <= (i-j+1); x++) {
                f[i][j] = min(f[i][j], f[i-x][j-1] + w[i-x+1][i]);
            }
        }
    }
    
    cout << f[n][k] << endl;
    return 0;
}
