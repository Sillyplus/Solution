/*******************************************************************************
	> File Name: 1528.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Sep 22 21:17:25 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;


int main(int argc, char* argv[]) {
    int n, p;
    while (scanf("%d%d", &n, &p) == 2 && !(n == 0 && p == 0)) {
        long long ans = 1;
        for (int i = 2; i <= n; ++i) {
            ans = ans * i % p;
        }
        cout << ans << endl;
    }
    return 0;
}
