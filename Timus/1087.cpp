/*******************************************************************************
	> File Name: 1087.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon Jun  1 16:54:23 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;

int f[MAXN] = {0};
int k[100];

int main(int argc, char* argv[]) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> k[i];
    }
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((i-k[j] > 0) && f[i-k[j]] == 0) {
                f[i] = 1;
                break;
            }
        }
    }
    cout << (f[n] == 1 ? 1 : 2) << endl;
    return 0;
}
