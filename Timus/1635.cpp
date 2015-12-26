/*******************************************************************************
    > File Name: 1635.cpp
    > Author: sillyplus
    > Mail: oi_boy@sina.cn
    > Created Time: Thu Dec 17 08:44:06 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4e3 + 10;

string s;
bool pd[MAXN][MAXN];
int pre[MAXN], f[MAXN];

void output(int p) {
    if (pre[p] == -1) {
        for (int i = 0; i <= p; ++i) {
            cout << s[i];
        }
    } else {
        output(pre[p]);
        cout << " ";
        for (int i = pre[p]+1; i <= p; ++i) {
            cout << s[i];
        }
    }
}

int main(int argc, char* argv[]) {
    cin >> s;
    int n = s.size();

    memset(pd, false, sizeof(pd));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + i < n; ++j) {
            if (i == 0) {
                pd[j][j + i] = true;
            } else if (i == 1) {
                if (s[j] == s[j + i]) {
                    pd[j][j + i] = true;
                }
            } else {
                if (s[j] == s[j + i]) {
                    pd[j][j + i] = pd[j + 1][j + i - 1];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        f[i] = i + 1;
        pre[i] = i - 1;
        if (pd[0][i]) {
            f[i] = 1;
            pre[i] = -1;
            continue;
        }
        for (int j = i - 1; j >= 0; --j) {
            if (pd[j + 1][i]) {
                if (f[i] > f[j] + 1) {
                    f[i] = f[j] + 1;
                    pre[i] = j;
                }
            }
        }
    }

    cout << f[n-1] << endl;
    output(n-1);
    cout << endl;
    return 0;
}
