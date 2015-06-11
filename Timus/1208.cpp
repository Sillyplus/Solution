/*******************************************************************************
	> File Name: 1208.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Thu Jun 11 13:40:20 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20;

map<string, bool> mp;
vector<string> team[MAXN];

int n, ans;

void dfs(int k, int x) {
    ans = max(ans, x);
    for (int i = k; i < n; ++i) {
        if (!mp[team[i][0]] && !mp[team[i][1]] && !mp[team[i][2]]) {
            mp[team[i][0]] = mp[team[i][1]] = mp[team[i][2]] = true;
            dfs(i+1, x+1);
            mp[team[i][0]] = mp[team[i][1]] = mp[team[i][2]] = false;
        }
    }
}

int main(int argc, char* argv[]) {
    string t;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> t;
            mp[t] = false;
            team[i].push_back(t);
        }
    }
    ans = 0;
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}
