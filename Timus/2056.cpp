/*******************************************************************************
	> File Name: 2056.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri Jun 19 07:28:15 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    int n, x;
    double ans = 0.0;
    bool flag = false;
    string s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x == 3) {
            cout << "None" << endl;
            return 0;
        }
        if (x != 5) {
            flag = true;
        }
        ans += x;
    }
    ans /= double(n);
    if (!flag) {
        cout << "Named" << endl;
    } else if (ans >= 4.5) {
        cout << "High" << endl;
    } else {
        cout << "Common" << endl;
    }
    return 0;
}
