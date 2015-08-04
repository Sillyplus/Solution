/*******************************************************************************
	> File Name: 1964.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Thu Jul 30 14:27:32 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int a[100];

int main(int argc, char* argv[]) {
    int n, k;
    cin >> k >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int tmp = a[0];
    for (int i = 1; i < n; i++) {
        tmp = tmp + a[i] - k;
        if (tmp <= 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << tmp << endl;
    return 0;
}
