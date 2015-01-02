/*******************************************************************************
	> File Name: 1327.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri Jan  2 11:33:59 2015
 ******************************************************************************/

#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int ans = (b - a) / 2;
    if (a % 2 || b % 2)
        ans++;
    cout << ans << endl;
    return 0;
}
