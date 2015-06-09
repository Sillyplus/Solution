/*******************************************************************************
	> File Name: 1280.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Jun  9 14:47:40 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;

vector<int> e[MAXN];
int du[MAXN] = {0};

int main(int argc, char* argv[]) {
    int n, m, u, v, k;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        e[u].push_back(v);
        du[v]++;
    }
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        if (du[k] != 0) {
            flag = false;
            break;
        } else {
            for (int j = 0; j < e[k].size(); ++j) {
                du[e[k][j]]--;
            }
        }
    }
    if (flag) 
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    return 0;
}
