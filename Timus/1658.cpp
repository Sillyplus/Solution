/*******************************************************************************
    > File Name: 1658.cpp
    > Author: sillyplus
    > Mail: oi_boy@sina.cn
    > Created Time: Sun Dec 13 21:58:40 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 910;
const int MAXM = 8110;

int f[MAXN][MAXM], pre[MAXN][MAXM];

int main(int argc, char* argv[]) {
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXM; ++j) {
            f[i][j] = 101;
        }
    }
    f[0][0] = 0;
    for (int i = 1; i <= 900; ++i) {
        for (int j = i; j <= 8100 && j <= i * i; ++j) {
            for (int k = 1; k <= 9 && k <= i && k * k <= j; ++k) {
                if (i - k > j - k * k) {
                    break;
                }
                if (f[i][j] > f[i - k][j - k * k] + 1) {
                    pre[i][j] = k;
                    f[i][j] = f[i - k][j - k * k] + 1;
                }
            }
        }
    }
    /*
     *for (int i = 0; i < 10; ++i) {
     *    for (int j = 0; j < 10; ++j) {
     *        cout << f[i][j] << " ";
     *    }
     *    cout << endl;
     *}
     */

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (n > m || n > 900 || m > 8100 || (n ^ m) & 1 || f[n][m] > 100) {
            cout << "No solution" << endl;
            continue;
        }
        while (n && m) {
            int tmp = pre[n][m];
            cout << pre[n][m];
            n -= tmp;
            m -= tmp * tmp;
        }
        cout << endl;
    }
    return 0;
}
