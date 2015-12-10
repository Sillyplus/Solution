/*******************************************************************************
	> File Name: 1431.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon Dec  7 09:59:59 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int a[40];

int main(int argc, char* argv[]) {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        a[k]++;
    }
    int ans = 0;
    for (int i = 1; i <= 30; ++i) {
        if (a[i]) {
            if (a[i+1]) {
                ans += min(a[i], a[i+1]);
                if (a[i+1] >= a[i]) {
                    a[i+1] -= a[i];
                } else {
                    ans += a[i] - a[i+1];
                    a[i+1] = 0;
                } 
            } else {
                ans += a[i];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
