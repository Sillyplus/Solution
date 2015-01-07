/*******************************************************************************
	> File Name: 1457.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Wed Jan  7 21:02:52 2015
 ******************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> k;
        ans += k;
    }
    ans /= n;
    printf("%.6f\n", ans);    
    return 0;
}
