/*******************************************************************************
	> File Name: 1644.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Thu Jan  8 23:22:35 2015
 ******************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, k, mx = 10, mi = 0;
    string  s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k >> s;
        if (s == "hungry") {
            mi = max(mi, k);
        } else {
            mx = min(mx, k);
        }
    }
    if (mi >= mx) {
        cout << "Inconsistent" << endl;
    } else {
        cout << mx << endl;
    }
    return 0;
}
