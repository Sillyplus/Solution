/*******************************************************************************
	> File Name: 1931.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Wed Jun  3 00:47:43 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int a[MAXN];

int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int ans = 0, cnt = 0, now = 1, tmp = 0;
    for (int i = 2; i <= n+1; ++i) {
        tmp++;
        if (a[i] < a[now]) {
            if (cnt < tmp) {
                ans = now;
                cnt = tmp;
            }
            now = i, tmp = 1;
        }
    }
    if (tmp > cnt) {
        ans = now;
    }
    cout << ans << endl;
    return 0;
}
