/*******************************************************************************
	> File Name: 1023.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Thu Nov 13 17:01:19 2014
 ******************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 2; i < n; i++) {
        if (n % (i+1) == 0) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
