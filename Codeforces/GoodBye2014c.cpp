/*******************************************************************************
	> File Name: c.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Dec 30 23:52:31 2014
 ******************************************************************************/

#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

map<int, int> mp;
vector<int> v;
set<int> s;

int main() {
    int n, m, k;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        mp[i] = k;       
    }
    for (int i = 0; i < m; i++) {
        cin >> k;
        v.push_back(k);
    }    
    int ans = 0;
    for (int i = m-1; i > 0; i--) {
        s.clear();
        int tmp = i-1;
        while (tmp >= 0 && v[tmp] != v[i]) {
            if (s.find(v[tmp]) == s.end()) {
                ans += mp[v[tmp]];
                s.insert(v[tmp]);
            }
            tmp--;
        }
    }
    cout << ans << endl;
    return 0;
}
