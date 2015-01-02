/*******************************************************************************
	> File Name: 1203.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri Jan  2 16:11:38 2015
 ******************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio> 
#include <vector>

using namespace std;

const int MAXN = 100010;

vector<pair<int, int> > v(MAXN);

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second != b.second)
        return a.second < b.second;
    else 
        return a.first < b.first;
}
int main() {
    int n, l, r;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &l, &r);
        v[i] = make_pair(l, r);
    }
    sort(v.begin(), v.begin()+n, comp);
    int cnt = 0, pos = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].first > pos) {
            cnt++;
            pos = v[i].second;
        } 
    }
    cout << cnt << endl;
    return 0;
}
