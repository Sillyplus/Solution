/*******************************************************************************
	> File Name: 1572.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Jun  9 00:00:50 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    int t, tt, ans = 0;
    double l, ll;
    cin >> t >> l;
    if (t == 1) {
        l *= 2;
    } else if (t == 2) {
        l *= sqrt(2);
    } 
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tt >> ll;
        if (tt == 1) {
            ll *= 2;
        } else if (tt == 3) {
            ll = ll * sqrt(3) / 2;
        }
        if (ll <= l) ans++;
    }
    cout << ans << endl;
    return 0;
}
