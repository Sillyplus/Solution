/*******************************************************************************
	> File Name: D2-337A.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri Jan  8 00:18:44 2016
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    int ans = 0;
    if (n % 2 == 0) {
        ans = n / 4;
        if (n % 4 == 0) {
            ans -= 1;
        }
    }
    cout << ans << endl;
    return 0;
}
