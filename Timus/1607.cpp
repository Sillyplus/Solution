/*******************************************************************************
	> File Name: 1607.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri Jan  2 15:07:39 2015
 ******************************************************************************/

#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans;
    if (a > c) {
        cout << a << endl;
        return 0;
    }
    for (;;) {
        if (a + b >= c) {
            ans = c;
            break;
        } else {
            a += b;
        }
        if (c - d <= a) {
            ans = a;
            break;
        } else {
            c -= d;
        }
    }
    cout << ans << endl;
    return 0;
}
