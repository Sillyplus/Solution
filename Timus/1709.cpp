/*******************************************************************************
	> File Name: 1709.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Jun  9 08:45:09 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 10;

char m[MAXN][MAXN];
int fa[MAXN];

int getFa(int x) {
    return (fa[x] == x ? fa[x] : fa[x] = getFa(fa[x]));
}

int main(int argc, char* argv[]) {
    int n, d, a;
    cin >> n >> d >> a;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) fa[i] = i;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int fi = getFa(i);
            int fj = getFa(j);
            if (m[i][j] == '1') {
                if (fi != fj) {
                    fa[fj] = fi;
                    m[i][j] = m[j][i] = '0';
                } else {
                    m[i][j] = m[j][i] = 'd';
                    ans += d;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; ++j) {
            int fi = getFa(i);
            int fj = getFa(j);
            if (fi != fj) {
                m[i][j] = m[j][i] = 'a';
                ans += a;
                fa[fj] = fi;
            }
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; ++i) {
        cout << m[i] << endl;
    }
    return 0;
}
