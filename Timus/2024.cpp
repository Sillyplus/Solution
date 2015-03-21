/*******************************************************************************
	> File Name: 2024.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri Mar 20 20:55:40 2015
 ******************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string s;
vector<int> a(30);

int k, n, m;

long long cb(int x, int y) {
    long long ret = 1;
    for (int i = 1; i <= y; i++) {
        ret = ret * (x-i+1) / i;
    }
    return  ret;
}

int main() {
    cin >> s;
    cin >> k;
    for (int i = 0; i < s.size(); i++) {
        a[s[i] - 'a']++;
    }
    sort(a.begin(), a.end(), std::greater<int>());
    int sum = 0;
    long long times = 1;
    n = m = 0;
    for (int i = 0; i < k; i++) {
        sum += a[i];
        if (a[i] == a[k-1]) m++;
    }
    if (a[k-1] > 0) {
        for (int i = 0; i < 26; i++) {
            if (a[i] == a[k-1]) n++;
        }
        times = cb(n, m);
    }
    cout << sum << " " << times << endl;
    return 0;
}
