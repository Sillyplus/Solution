/*******************************************************************************
	> File Name: 1991.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri Jan  2 11:22:57 2015
 ******************************************************************************/

#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int ans1 = 0, ans2 = 0, tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp > k)
            ans1 += (tmp - k);
        else 
            ans2 += (k - tmp);
    }
    cout << ans1 << " " << ans2 << endl; 
    return 0;
}
