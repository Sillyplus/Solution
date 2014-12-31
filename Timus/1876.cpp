/*******************************************************************************
	> File Name: 1876.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Wed Dec 31 16:52:11 2014
 ******************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int ans = 39 + 39 * 2;
    a -= 39;
    b -= 39;
    int tmp1, tmp2;
    tmp1 = 1 + (a - 1) * 2 + 1;
    tmp2 = 1 + b * 2;
    cout << ans + max(tmp1, tmp2) << endl;
    return 0;
}
