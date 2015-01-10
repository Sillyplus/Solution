/*******************************************************************************
	> File Name: 1902.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat Jan 10 16:12:07 2015
 ******************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    double t, s, si, ans;
    cin >> n >> t >> s;
    for (int i = 0; i < n; i++) {
        cin >> si;
        ans = s + (t + si - s) / 2.0;
        printf("%.6f\n", ans);
    }
    cout << endl;
    return 0;
}
