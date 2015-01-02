/*******************************************************************************
	> File Name: 1104.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Fri Jan  2 15:19:04 2015
 ******************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 1000010;

string s;

bool check(int k) {
    int tmp = 0, md = k-1;
    for (int i = 0; i < s.size(); i++) {
        int now;
        if (s[i] >= '0' && s[i] <= '9') {
            now = s[i] - '0';
        } else {
            now = s[i] - 'A' + 10;
        }
        if (now > md) {
            return false;
        }
        tmp = tmp * k + now;
        tmp %= md;
    }
    if (tmp == 0)
        return true;
    else
        return false;
}

int main() {
    cin >> s;
    int ans = 0;
    for (int i = 2; i <= 36; i++) {
        if (check(i)) {
            ans = i;
            break;
        }
    }
    if (ans) {
        cout << ans << endl;
    } else {
        cout << "No solution." << endl;
    }
    return 0;
}
