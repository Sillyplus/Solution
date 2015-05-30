/*******************************************************************************
	> File Name: 1283.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Thu May 28 00:18:19 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    long long ans = 0;
    double a, b, c;
    cin >> a >> b >> c;
    while (a > b) {
        a -= a * c / 100;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
