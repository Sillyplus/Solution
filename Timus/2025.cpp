/*******************************************************************************
	> File Name: 2025.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Thu Jan 15 00:01:18 2015
 ******************************************************************************/

#include <iostream>

using namespace std;

typedef long long LL;
const int MAXN = 1e4 + 10;

LL a[MAXN];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < k; i++)
            a[i] = n / k;
        for (int i = 0; i < (n % k); i++)
            a[i]++;
        LL ans = 0;
        for (int i = 0; i < k; i++)
            ans += (a[i] * (n-a[i]));
        cout << ans / 2 << endl;
    }
    return 0;
}
