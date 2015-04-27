/*******************************************************************************
	> File Name: 1683.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri Apr 24 09:11:05 2015
*******************************************************************************/

#include <iostream>

using namespace std;

const int MAXN = 10010;

int a[MAXN] = {0};

int main() {
    int n, ans;
    cin >> n;
    for (ans = 1; n / 2; ans++) {
        a[ans] = n / 2;
        n = (n/2) + (n%2);
    }
    cout << ans-1 << endl; 
    for (int i = 1; i < ans; i++) 
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
