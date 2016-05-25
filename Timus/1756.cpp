/*******************************************************************************
	> File Name: 1756.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Thu May 26 00:39:29 2016
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    int m, d1, d2, k, t;
    cin >> m >> d1 >> d2;
    k = (m * d1) % d2;
    t = (m * d1) / d2;
    if (k) {
        for (int i = 0; i < (d2 - k); ++i) {
            cout << t << " ";
        }
        for (int i = 0; i < k; ++i) {
            cout << t + 1 << " ";
        }
        cout << endl;
    } else {
        for (int i = 0; i < d2; ++i) {
            cout << t << " ";
        }
        cout << endl; 
    }
    return 0;
}
