/*******************************************************************************
	> File Name: b.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat May 23 00:39:52 2015
*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 3010;

int a[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) {
            ans++;
            a[i]++;
        } else if (a[i] < a[i-1]) {
            ans += a[i-1] - a[i] + 1;
            a[i] = a[i-1] + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
