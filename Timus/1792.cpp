/*******************************************************************************
	> File Name: 1792.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Wed Jan  7 21:19:39 2015
 ******************************************************************************/

#include <iostream>

using namespace std;

int a[10];

bool check() {
    if (a[4] != (a[1]+a[2]+a[3]) % 2 || 
        a[5] != (a[0]+a[2]+a[3]) % 2 ||
        a[6] != (a[0]+a[1]+a[3]) % 2)
        return false;
    return true;
}
int main() {
    for (int i = 0; i < 7; i++) 
        cin >> a[i];
    if (!check()) {
        for (int i = 0; i < 7; i++) {
            a[i] = 1 - a[i];
            if (check()) 
                break;
            a[i] = 1 - a[i];
        }
    }
    for (int i = 0; i < 7; i++)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}
