/*******************************************************************************
	> File Name: 1613.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Thu May 14 09:14:18 2015
*******************************************************************************/

#include <iostream>
#include <map>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

map<int, vector<int> > mp;

int main() {
    int n, m, x, l, r;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        mp[x].push_back(i+1);
    }
    string ans = "";
    cin >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &l, &r, &x);
        if (!mp[x].empty()) {
            vector<int>::iterator its;
            its = lower_bound(mp[x].begin(), mp[x].end(), l);
            if (its == mp[x].end()) {
                ans += '0';   
            } else if (*its <= r) {
                ans += '1';
            } else ans += '0';
        } else {
            ans += '0';
        }
    }
    cout << ans << endl;
    return 0;
}
