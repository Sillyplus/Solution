/*******************************************************************************
	> File Name: 1753.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Wed Oct 14 00:45:15 2015
*******************************************************************************/

#include <bits/stdc++.h>

const double EPS = 1e-9;
const double PI = 3.14159265358979;

using namespace std;

int main(int argc, char* argv[]) {
    double h, H, l;
    cin >> h >> H >> l;
    double left, right, mid;
    left = 0;
    right = PI / 2;
    mid = (left + right) / 2;
    while (abs(left - right) > EPS) {
        double tmp, s = sin(mid);
        tmp = (h / (s * s)) - (H * s / 2);
        if (tmp > 0) {
            left = mid;
        } else {
            right = mid;
        }
        mid = (left + right) / 2;
    }
    double ans;
    ans = H / 2 * cos(mid) - h / tan(mid);
    printf("%.6lf\n", ans);
    return 0;
}
