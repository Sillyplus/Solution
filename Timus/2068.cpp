/*******************************************************************************
	> File Name: 2068.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat May 21 01:13:34 2016
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    int n, k;
    cin >> n;
    int t = 0;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        t += k / 2;
    }
    if (t % 2) {
        cout << "Daenerys" << endl;
    } else {
        cout << "Stannis" << endl;
    }
    return 0;
}
