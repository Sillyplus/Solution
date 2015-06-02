/*******************************************************************************
	> File Name: 1002.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Jun  2 01:15:50 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e4 + 10;
const int MAXM = 3e2 + 10; // what the Big F..., there is more than 100 digits..
const int INF = 1e9;

int len[MAXN], f[MAXM], pre[MAXM], ans[MAXM], n, l;
char b[MAXM], s[MAXM], w[MAXN][MAXM];

inline bool check(int x, int j) {
    for (int i = 1; i <= len[j]; ++i) {
        if (s[x+i] != b[w[j][i-1]]) {
            return false;
        }
    }    
    return true;
}

int main(int argc, char* argv[]) {
    b['i'] = b['j'] = '1'; b['a'] = b['b'] = b['c']='2';
    b['d'] = b['e'] = b['f'] = '3'; b['g'] = b['h'] = '4';
    b['k'] = b['l'] = '5'; b['m'] = b['n'] = '6';
	b['p'] = b['r'] = b['s'] = '7'; b['t'] = b['u'] = b['v'] = '8';
    b['w'] = b['x'] = b['y'] = '9'; b['o'] = b['q'] = b['z'] = '0';
    gets(s);
    while (s[0] != '-') { 
        l = strlen(s);
        for (int i = l; i > 0; --i)
            s[i] = s[i-1];
        scanf("%d\n", &n);
        for (int i = 1; i <= n; ++i) {
            gets(w[i]);
            len[i] = strlen(w[i]);
        }
        for (int i = 0; i <= l; ++i)
            f[i] = INF;
        memset(pre, 0, sizeof(pre));
        f[0] = 0;
        for (int i = 0; i < l; ++i) {
            for (int j = 1; j <= n; ++j) {
                if ((i+len[j] <= l) && (f[i]+1 < f[i+len[j]]) && check(i, j)) {
                    f[i+len[j]] = f[i]+1; 
                    pre[i+len[j]] = j;
                }
            }
        }
        if (f[l] == INF) {
            cout << "No solution." << endl;
        } else {
            int k = 0;
            for (int i = l; i > 0; i -= len[pre[i]])
                ans[++k] = pre[i];
            for (int i = k; i > 0; --i)
                printf("%s%c", w[ans[i]], (i != 1) ? ' ' : '\n');
        }
        gets(s);
    }
    return 0;
}
