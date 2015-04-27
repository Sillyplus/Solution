/*******************************************************************************
	> File Name: 2018.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Thu Apr 23 07:35:40 2015
*******************************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 310;
const int MOD = 1e9 + 7;

int f[2][2][MAXN];

int main() {
    int n, a, b;
    cin >> n >> a >> b; 

    f[0][0][0] = f[0][1][0] = 1;

    for (int i = 1; i <= n; i++) {
        int now = i & 1;
        int pre = (i-1) & 1;
        memset(f[now], 0, sizeof(f[now]));

        for (int j = 1; j <= a; j++) {
            f[now][0][j] += f[pre][0][j-1];
            f[now][0][j] %= MOD;
            f[now][1][1] += f[pre][0][j];
            f[now][1][1] %= MOD;
        }
        for (int j = 1; j <= b; j++) {
            f[now][1][j] += f[pre][1][j-1];
            f[now][1][j] %= MOD;
            f[now][0][1] += f[pre][1][j];
            f[now][0][1] %= MOD;
        }
    }
 
    int ans = 0;
    for (int i = 1; i <= a; i++) {
        ans += f[n & 1][0][i];
        ans %= MOD;
    }
    for (int i = 1; i <= b; i++ ) {
        ans += f[n & 1][1][i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
