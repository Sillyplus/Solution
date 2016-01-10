/*******************************************************************************
	> File Name: D2-337B.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri Jan  8 00:34:36 2016
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

long long a[MAXN];

int main(int argc, char* argv[]) {
    int n, k;
    long long mi = 1e9;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[n+i] = a[i];
        mi = min(mi, a[i]);
    }
    long long ans = 0, tmp = 0;
    for (int i = 0; i < 2*n; ++i) {
        if (a[i] > mi) {
            tmp++;
        } else {
            tmp = 0;
        }
        ans = max(ans, tmp);
    }
    ans += n * mi;
    cout << ans << endl;
    return 0;
}
