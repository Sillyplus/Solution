/*******************************************************************************
	> File Name: 1032.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon Jun 15 00:54:23 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;

int a[MAXN], sum[MAXN], f[MAXN];

int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = (sum[i-1] + a[i]) % n;
    }
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; ++i) {
        if (f[sum[i]] != 0 || sum[i] == 0) {
            cout << i - f[sum[i]] << endl;
            for (int j = f[sum[i]]+1; j <= i; ++j) {
                cout << a[j] << endl;
            }
            break;
        }
        f[sum[i]] = i;
    }
    return 0;
}
