/*******************************************************************************
	> File Name: 2021.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon Jun  1 09:14:37 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > a;
vector<pair<int, int> > b;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

int main(int argc, char* argv[]) {
    int n, x, sum1 = 0, sum2 = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a.push_back(make_pair(i+1, x));
        sum1 += x;
    }
    for (int i = 0; i < n; ++i) {
        cin >> x;
        b.push_back(make_pair(i+1, x));
        sum2 += x;
    }
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);
    if (sum1 > sum2) {
        reverse(b.begin(), b.end());
    } else {
        reverse(a.begin(), a.end());
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i].first << " " << b[i].first << endl;
    }
    return 0;
}
