/*******************************************************************************
	> File Name: 2000.cpp
	> Author: sillyplus
	> Mail: oi_boy@sina.cn
	> Created Time: Tue Nov 25 18:50:35 2014
 ******************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 25010;

int a[MAXN] ,c[10];
double b[MAXN];

int main() {
    int n, ans = 0, x = 0, k;
    double tmp;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k >> a[i];
        b[i] = k * 1.0 / a[i];
    }
    for (int i = 1; i < 4; i++) {
        tmp = -1;
        for (int j = 1; j <= n; j++) {
            if (b[j] > tmp) {
                tmp = b[j];
                x = j;
            }
        }
        ans += a[x];
        b[x] =  -1;
        c[i] = x;
    }
    cout << ans << endl;
    for (int i = 1; i < 4; i++)
        cout << c[i] << endl;
    return 0;
}
