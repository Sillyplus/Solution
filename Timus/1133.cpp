/*******************************************************************************
	> File Name: 1133.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Wed Jan  7 22:23:36 2015
 ******************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 2014;

long double f[MAXN];

int main() {
    f[0] = f[1] = 1;
    for (int i = 2; i < MAXN; i++)
        f[i] = f[i-1] + f[i-2];
    int x, y, n;
    long double fx, fy, a;
    cin >> x >> fx >> y >> fy >> n;
    if (x > y) {
        swap(x, y);
        swap(fx, fy);
    }
    if (y - x >= 2)
        a = (fy - f[y-x-2] * fx) / f[y-x-1];
    else if (y - x == 1)
        a = fy;
    else
        a = fx;
    f[x+1000] = fx;
    f[x+1001] = a;
    if (n > x) {
        for (int i = x + 1002; i <= n + 1000; i++)
            f[i] = f[i-1] + f[i-2];
    } else {
        for (int i = x + 999; i >= n + 1000; i--)
            f[i] = f[i-2] - f[i-1];
    }
    long double ans = f[n + 1000];
    printf("%.Lf\n", ans);
    return 0;
}
