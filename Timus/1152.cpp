/*******************************************************************************
    > File Name: 1152.cpp
    > Author: sillyplus
    > Mail: oi_boy@sina.cn
    > Created Time: Sat Dec 26 10:35:21 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = (1 << 22);

int a[MAXN], f[MAXN], h[MAXN];

int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i & (1 << j)) != 0) {
                h[i] += a[j];
            }
        }
    }
    int st = (1 << n) - 1;
    f[st] = 0;
    for (int i = st; i >= 0; i--) {
        for (int j = 0; j < n; ++j) {
            int x = i;
            if ((i & (1 << j)) != 0) {
                if (j == 0) {
                    x = x & (st - (1 << (n - 1)));
                } else {
                    x = x & (st - (1 << (j - 1)));
                }

                x -= 1 << j;

                if (j == n - 1) {
                    x = x & (st - 1);
                } else {
                    x = x & (st - (1 << (j + 1)));
                }
                f[x] = min(f[x], f[i] + h[x]);
            }
        }
    }
    cout << f[0] << endl;
    return 0;
}
