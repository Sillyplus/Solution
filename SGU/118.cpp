/*******************************************************************************
	> File Name: 118.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sun May 31 08:45:49 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int DR(int x) {
    return (x - 1) % 9 + 1;
}

int main(int argc, char* argv[]) {
    int n, t;
    cin >> t;
    while (t--) {
        int ans = 0, tmp = 1, x;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x;
            tmp = tmp * (x % 9) % 9;
            ans += tmp;
        }
        ans %= 9;
        if (!ans) printf("9\n");
        else printf("%d\n", ans);
    }
    return 0;
}
