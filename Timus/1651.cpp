/*******************************************************************************
	> File Name: 1651.cpp
	> Author: sillyplus
	> Mail: oi_boy@sina.cn
	> Created Time: Sat Sep 12 04:56:13 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10010;
const int INF = 1e9;

int f[MAXN],pre[MAXN*10],pos[MAXN], ans[MAXN], a[MAXN*10];
int n;

int main(int argc, char* argv[]) {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 0; i < MAXN; ++i) f[i] = INF;
    memset(pre,0,sizeof(pre));
    f[a[1]] = 0;
    pos[a[1]] = 1;
    for (int i = 2; i <= n; ++i) {
        if (f[a[i-1]] + 1 < f[a[i]]) {
            f[a[i]] = f[a[i-1]] + 1 ;
            pre[i] = pos[a[i-1]];
            pos[a[i]] = i;
        }
    }

    int p = pos[a[n]];
    int sa = 0;
    while (p != 1) {
        ans[++sa] = a[p];
        p = pre[p];
    }
    cout << a[1];
    for (int i = sa; i > 0; i--)
        cout << " " << ans[i];
    cout << endl;
    return 0;
}
