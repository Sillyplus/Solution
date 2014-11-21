/*******************************************************************************
	> File Name: 3499.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri Nov 14 20:50:43 2014
 ******************************************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n;
        int mx = -1, mn = 101;
        int sum = 0;
        for (int i = 0; i < n ; i++) {
            cin >> k;
            sum += k;
            mx = max(mx, k);
            mn = min(mn, k);
        }
        double ans = (sum - mx - mn) * 1.0 / (n - 2);
        printf("%.2f\n", ans);
    }
    return 0;
}
