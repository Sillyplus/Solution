/*******************************************************************************
	> File Name: 2000.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat Jan 31 09:11:35 2015
 ******************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN = 1e5 + 10;

int a[MAXN], sum[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] += sum[i-1] + a[i];
    }
    int x, y, s1, s2;
    cin >> x >> y;
    if (x == y) {
        s1 = sum[x];
        s2 = sum[n] - sum[x-1];
        s1 = max(s1, s2);
        s2 = sum[n] - s1;
    } else {
        if (x < y) {
            int mid = x + (y - x) / 2;
            s1 = sum[mid];
            s2 = sum[n] - s1;
        } else if (y < x) {
            int mid = x - (x - y) / 2;
            s2 = sum[mid-1];
            s1 = sum[n] - s2;
        }
    }
    cout << s1 << " " << s2 << endl;
    return 0;
}
