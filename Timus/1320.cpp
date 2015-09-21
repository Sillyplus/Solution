/*******************************************************************************
	> File Name: 1320.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri Sep 11 23:32:49 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;

int fa[MAXN], c[MAXN];

int getFa(int x) {
    return x == fa[x] ? x : fa[x] = getFa(fa[x]);
}

int main(int argc, char* argv[]) {
    int u, v, tu, tv;
    for (int i = 0; i < MAXN; ++i) 
        fa[i] = i;
    int f1, f2;
    while (cin >> u >> v) {
        f1 = getFa(u);
        f2 = getFa(v);
        if (f1 != f2) {
            c[f1] += c[f2];
            fa[f2] = f1; 
        }
        c[f1]++;
    }
    for (int i = 1; i <= 1000; ++i) {
        if ((fa[i] == i) && (c[i] % 2 == 1)) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}
