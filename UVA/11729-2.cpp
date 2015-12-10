/*******************************************************************************
	> File Name: 11729.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat Dec  5 10:40:17 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

bool cmp(const pii & a, const pii & b) {
    if (a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second > b.second;
    }
}

int main(int argc, char* argv[]) {
    int n;
    int cnt = 0;
    while (cin >> n && n != 0) {
        cnt++;
        pii k;
        vector<pii> v;
        for (int i = 0; i < n; ++i) {
            cin >> k.first >> k.second;
            v.push_back(k);
        }
        sort(v.begin(), v.end(), cmp);
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; ++i) {
            ans1 += v[i].first;
            ans2 = max(ans2, ans1 + v[i].second);
        }
        printf("Case %d: %d\n", cnt, max(ans1, ans2));
    }
    return 0;
}
