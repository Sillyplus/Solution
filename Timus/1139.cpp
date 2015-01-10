/*******************************************************************************
	> File Name: 1139.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat Jan 10 15:12:55 2015
 ******************************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main() {
    int n, m;
    cin >> n >> m;
    n--, m--;
    int a = gcd(n, m);
    cout << n + m - a << endl;
    return 0;
}
