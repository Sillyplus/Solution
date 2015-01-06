/*******************************************************************************
	> File Name: 1925.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Tue Jan  6 09:56:56 2015
 ******************************************************************************/

#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int b, g, tmp1 = 0, tmp2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> b >> g;
        tmp1 += b;
        tmp2 += g;
    }
    tmp1 += k;
    if (tmp1 >= tmp2 + (n+1) * 2) 
        cout << (tmp1 - tmp2 - (n+1)*2) << endl;
    else
        cout << "Big Bang!" << endl;
    return 0;
}
