/*******************************************************************************
	> File Name: 1112.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon Jun  1 21:41:14 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > v;
bool f[110];

int main(int argc, char* argv[]) {
    int n, l, r;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        v.push_back(make_pair(min(l, r), max(l, r)));
    }
    memset(f, true, sizeof(f));
    sort(v.begin(), v.end());
    int ans = n;
    for (int i = v.size()-1; i >= 0; --i) {
        if (f[i]) {
            for (int j = i-1; j >= 0; --j) {
                if (v[j].second > v[i].first) {
                    f[j] = false;
                    ans--;
                } else break;
            }
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; ++i)
        if (f[i])
            cout << v[i].first << " " << v[i].second << endl;
    return 0;
}
