/*******************************************************************************
	> File Name: a.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat May 23 00:12:37 2015
*******************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    long long k, n, w;
    cin >> k >> n >> w;
    long long total = (1 + w) * w / 2 * k;
    if (total <= n) {
        cout << 0 << endl;
    } else {
        cout << total - n << endl;
    }
    return 0;
}
