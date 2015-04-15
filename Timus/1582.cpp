/*******************************************************************************
	> File Name: 1582.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Thu Apr 16 00:03:37 2015
*******************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    double k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    double ans = (1000/(1/k1+1/k2+1/k3));
    printf("%.0lf\n", ans);
    return 0;
}
