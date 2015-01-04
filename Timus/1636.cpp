/*******************************************************************************
	> File Name: 1636.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sun Jan  4 07:20:37 2015
 ******************************************************************************/

#include <iostream>

using namespace std;

int main() {
    int t1, t2;
    cin >> t1 >> t2;
    int tmp = 0, k;
    for (int i = 0; i < 10; i++) {
        cin >> k;
        tmp += k;
    }
    if ((t2 - tmp * 20) < t1)
        cout << "Dirty debug :(" << endl;
    else 
        cout << "No chance." << endl;
    return 0;
}
