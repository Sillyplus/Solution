/*******************************************************************************
	> File Name: 1272.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Jun  9 16:11:30 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;

int f[MAXN];

int get_father(int x) {
    return (f[x] == x ? f[x] : f[x] = get_father(f[x]));
}

int main(int argc, char* argv[]) {
    int n, k, m, u, v;
    cin >> n >> k >> m;
    for (int i = 1; i <= n; ++i) f[i] = i;
    for (int i = 0; i < k; ++i) {
        cin >> u >> v;
        int fu = get_father(u);
        int fv = get_father(v);
        f[fu] = fv;
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        int fu = get_father(u);
        int fv = get_father(v);
        if (fu != fv) {
            ans++;
            f[fu] = fv;
        }
    }
    cout << ans << endl;
    return 0;
}
