/*******************************************************************************
	> File Name: 1794.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Wed Jan 28 14:34:42 2015
 ******************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

const int MAXN = 1e5 + 10;

int a[MAXN];
map<int, int> mp;
map<int, int>::iterator itr;

int main() {
    int n, k;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        int x = (i+n+1 - k) % n;
        if (x == 0) x = n;
        mp[x]++; 
    }
    int tmp = -1, ans;
    for (itr = mp.begin(); itr != mp.end(); itr++) {
        if (itr->second > tmp) {
            tmp = itr->second;
            ans = itr->first;
        }
    }
    cout << ans << endl;
    return 0;
}
