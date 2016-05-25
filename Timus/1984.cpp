/*******************************************************************************
	> File Name: 1984.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Thu May 26 00:27:54 2016
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979;

int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    double ans;
    ans = n < 3 ? n : (1 / sin(PI / n) + 1);
    printf("%.6f\n", ans);
    return 0;
}
