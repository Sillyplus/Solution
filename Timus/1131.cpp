/*******************************************************************************
	> File Name: 1131.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Jan  6 10:18:26 2015
 ******************************************************************************/

#include <iostream>

using namespace std;

int main() {
    int n, k, ans;
    cin >> n >> k;
    for (ans = 0; (1 << ans) < k && (1 << ans) < n; ans++);
    if ((1 << ans) < n)
        ans += (n - (1 << ans) - 1) / k + 1;
    cout << ans << endl;
    return 0;
}
