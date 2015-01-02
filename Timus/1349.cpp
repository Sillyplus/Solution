/*******************************************************************************
	> File Name: 1349.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri Jan  2 14:53:38 2015
 ******************************************************************************/

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n > 2 || n < 1) {
        cout << -1 << endl;
    } else {
        if (n == 1) {
            cout << "1 2 3" << endl;
        } else {
            cout << "3 4 5" << endl;
        }
    }
    return 0;
}
