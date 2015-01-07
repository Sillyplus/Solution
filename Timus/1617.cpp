/*******************************************************************************
	> File Name: 1617.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Wed Jan  7 20:53:18 2015
 ******************************************************************************/

#include <iostream>

using namespace std;

int a[110];

int main() {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        a[k % 600]++;
    }
    int ans = 0;
    for (int i = 0; i <= 100; i++) {
        ans += (a[i] / 4);
    }
    cout << ans << endl;
    return 0;
}
