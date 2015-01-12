/*******************************************************************************
	> File Name: 1786.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sun Jan 11 23:49:17 2015
 ******************************************************************************/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string sd = "Sandro";

int getValue(string x) {
    int ret = 0;
    if (x[0] >= 'a' && x[0] <= 'z') ret++;
    if (x[0] != 's' && x[0] != 'S') ret++;
    for (int i = 1; i < 6; i++) {
        if (x[i] >= 'A' && x[i] <= 'Z') {
            ret++;
            x[i] = char(x[i] + 32);
        } 
        if (x[i] != sd[i]) ret++;
    }
    return ret * 5;
}

int main() {
    int ans = 120;
    string s, tmp;
    cin >> s;
    for (int i = 0; i <= (s.size() - 6); i++) {
        ans = min(ans, getValue(s.substr(i, 6)));
    }
    cout << ans << endl;
    return 0;
}
